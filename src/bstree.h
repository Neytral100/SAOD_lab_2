struct bstree {
    char* key;
    int value;
    struct bstree* left;
    struct bstree* right;
};

struct bstree* bstree_create(char*, int);
void bstree_add(struct bstree*, char*, int);
struct bstree* bstree_lookup(struct bstree*, char*);
void bstree_delete(struct bstree*, char*);
struct bstree* bstree_min(struct bstree*);
struct bstree* bstree_max(struct bstree*);