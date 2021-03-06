#include "hashtab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int hashtab_hash(char* key)
{
    unsigned int h = 0, hash_mul = 31;

    while (*key)
        h = h * hash_mul + (unsigned int)*key++;
    return h % HASHTAB_SIZE;
}

void hashtab_init(struct listnode** hashtab)
{
    for (int i = 0; i < HASHTAB_SIZE; i++)
        hashtab[i] = NULL;
}
