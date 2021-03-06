#define HASHTAB_SIZE 5051

struct listnode {
    char* key;
    int value;

    struct listnode* next;
};

struct listnode* hashtab[HASHTAB_SIZE];

unsigned int hashtab_hash(char*);
void hashtab_init(struct listnode**);