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

struct bstree* bstree_lookup(struct bstree* tree, char* key)
{
    while (tree != NULL) {
        if (key == tree->key) {
            return tree;
        } else if ((strcmp(key, tree->key)) < 0) {
            tree = tree->left;
        } else {
            tree = tree->right;
        }
    }
    return tree;
}

void bstree_delete(struct bstree* tree, char* key)
{
    struct bstree* node = bstree_lookup(tree, key);
    struct bstree* parent = tree;

    while ((parent->left != node) && (parent->right != node)) {
        if ((strcmp(parent->key, node->key)) < 0)
            parent = parent->left;
        else
            parent = parent->right;
    }

    if ((node->left == NULL) && (node->right == NULL)) {
        if (parent->left == node) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
    }

    if ((node->left != NULL) ^ (node->right != NULL)) {
        if (parent->left == node) {
            if (node->left != NULL)
                parent->left = node->left;
            else
                parent->left = node->right;
        } else {
            if (node->left != NULL)
                parent->right = node->left;
            else
                parent->right = node->right;
        }
    }

    if ((node->left != NULL) && (node->left != NULL)) {
        struct bstree* min_node = bstree_min(node->right);
        struct bstree* min_parent = node->right;
        while ((min_parent->left != min_node)
               && (min_parent->right != min_node)) {
            if ((strcmp(min_parent->key, min_node->key)) < 0)
                min_parent = min_parent->left;
            else
                min_parent = min_parent->right;
        }
        min_parent->left = min_node->right;
        if (parent->left == node)
            parent->left = min_node;
        else
            parent->right = min_node;
        min_node->left = node->left;
        min_node->right = node->right;
    }

    free(node);
}

struct bstree* bstree_min(struct bstree* tree)
{
    if (tree == NULL) {
        return NULL;
    }
    while (tree->left != NULL) {
        tree = tree->left;
    }
    return tree;
}

struct bstree* bstree_max(struct bstree* tree)
{
    if (tree == NULL) {
        return NULL;
    }
    while (tree->right != NULL) {
        tree = tree->right;
    }
    return tree;
}

void bstree_free(struct bstree* tree)
{
    if (tree->left != NULL)
        bstree_free(tree->left);
    if (tree->right != NULL)
        bstree_free(tree->right);
    /*
    free(&(tree->value));
    free(tree->key);
    free(tree->left);
    free(tree->right);
    */
    free(tree);
}