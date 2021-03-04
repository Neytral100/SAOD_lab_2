#include "bstree.h"
#include <stdio.h>
#include <stdlib.h>

struct bstree* bstree_create(char* key, int value)
{
    struct bstree* node;
    node = malloc(sizeof(*node));
    if (node != NULL) {
        node->key = key;
        node->value = value;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}