#define HASHTAB_SIZE 5051

struct listnode {
    char* key;
    int value;

    struct listnode* next;
};

struct listnode* hashtab[HASHTAB_SIZE];

unsigned int hashtab_hash(char*);
void hashtab_init(struct listnode**);
void hashtab_add(struct listnode**, char*, int);
struct listnode* hashtab_lookup(struct listnode**, char*);
void hashtab_delete(struct listnode**, char*);