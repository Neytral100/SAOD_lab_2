struct bstree {
    char* key;
    int value;
    struct bstree* left;
    struct bstree* right;
};

struct bstree* bstree_create(char*, int);
void bstree_add(struct bstree*, char*, int);