#include "bstree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void bstree_add(struct bstree* tree, char* key, int value)
{
    if (tree == NULL) {
        return;
    }
    struct bstree *parent, *node;
    while (tree != NULL) {
        parent = tree;
        if ((strcmp(key, tree->key)) < 0) {
            tree = tree->left;
        } else if ((strcmp(key, tree->key)) > 0) {
            tree = tree->right;
        } else {
            return;
        }
    }
    node = bstree_create(key, value);
    if ((strcmp(key, parent->key)) < 0) {
        parent->left = node;
    } else {
        parent->right = node;
    }
}