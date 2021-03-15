#define HASHTAB_SIZE 234989

unsigned int (*pHash)(char*);

struct listnode {
    char* key;
    int value;

    struct listnode* next;
};

struct listnode* hashtab[HASHTAB_SIZE];

unsigned int KRhash(char*);
unsigned int ELFhash(char*);
void hashtab_init(struct listnode**);
int hashtab_add(struct listnode**, unsigned int (*pHash)(char*), char*, int);
struct listnode*
hashtab_lookup(struct listnode**, unsigned int (*pHash)(char*), char*);
void hashtab_delete(struct listnode**, unsigned int (*pHash)(char*), char*);