#include "hashtab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int KRhash(char* key)
{
    unsigned int h = 0, hash_mul = 31;

    while (*key)
        h = h * hash_mul + (unsigned int)*key++;
    return h % HASHTAB_SIZE;
}

unsigned int ELFhash(char* key)
{
    unsigned int h = 0, g;
    while (*key) {
        h = (h << 4) + (unsigned int)key++;
        g = h & 0xF0000000L;
        if (g)
            h ^= g >> 24;
        h &= ~g;
    }
    return h % HASHTAB_SIZE;
}

void hashtab_init(struct listnode** hashtab)
{
    for (int i = 0; i < HASHTAB_SIZE; i++)
        hashtab[i] = NULL;
}

int hashtab_add(
        struct listnode** hashtab,
        unsigned int (*pHash)(char*),
        char* key,
        int value)
{
    struct listnode* node;
    int collision;
    int index = pHash(key);
    if (hashtab[index] != NULL)
        collision = 1;
    else
        collision = 0;
    node = malloc(sizeof(*node));
    if (node != NULL) {
        node->key = key;
        node->value = value;
        node->next = hashtab[index];
        hashtab[index] = node;
    }
    return collision;
}

struct listnode* hashtab_lookup(
        struct listnode** hashtab, unsigned int (*pHash)(char*), char* key)
{
    struct listnode* node;

    int index = pHash(key);
    for (node = hashtab[index]; node != NULL; node = node->next)
        if (0 == strcmp(node->key, key))
            return node;
    return NULL;
}

void hashtab_delete(
        struct listnode** hashtab, unsigned int (*pHash)(char*), char* key)
{
    struct listnode *node, *prev = NULL;
    int index = pHash(key);
    for (node = hashtab[index]; node != NULL; node = node->next) {
        if (0 == strcmp(node->key, key)) {
            if (prev == NULL)
                hashtab[index] = node->next;
            else
                prev->next = node->next;
            free(node);
            return;
        }
        prev = node;
    }
}