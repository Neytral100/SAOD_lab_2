#include "bstree.h"
#include "createarray.h"
#include "hashtab.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void experiment_one()
{
    clock_t start, end;
    float timer;
    int num_word;
    pHash = KRhash;
    struct bstree* bstree_find;
    struct listnode* hashtab_find;
    int size = 200000;
    char* word[size];
    create_array(word, size);
    FILE* bstree_pFile_exp1;
    FILE* hashtab_pFile_exp1;
    FILE* bstree_pFile_exp2;
    FILE* hashtab_pFile_exp2;

    if ((bstree_pFile_exp1 = fopen("../results/bstree1.txt", "w")) == NULL)
        printf("Error open file bstree1.txt\n");
    if ((hashtab_pFile_exp1 = fopen("../results/hashtab1.txt", "w")) == NULL)
        printf("Error open file hashtab1.txt\n");
    if ((bstree_pFile_exp2 = fopen("../results/bstree2.txt", "w")) == NULL)
        printf("Error open file bstree2.txt\n");
    if ((hashtab_pFile_exp2 = fopen("../results/hashtab2.txt", "w")) == NULL)
        printf("Error open file hashtab2.txt\n");
    srand(time(NULL));
    for (int i = 10000; i <= size; i += 10000) {
        printf("%d\n", i);
        fprintf(bstree_pFile_exp1, "%d ", i);
        fprintf(hashtab_pFile_exp1, "%d ", i);
        fprintf(bstree_pFile_exp2, "%d ", i);
        fprintf(hashtab_pFile_exp2, "%d ", i);
        struct bstree* tree;
        tree = bstree_create(word[0], 0);
        hashtab_init(hashtab);

        start = clock();
        for (int j = 1; j < i; j++)
            bstree_add(tree, word[j], j);
        end = clock();
        timer = difftime(end, start) / CLOCKS_PER_SEC;
        fprintf(bstree_pFile_exp2, "%f\n", timer);

        start = clock();
        for (int j = 1; j < i; j++)
            hashtab_add(hashtab, pHash, word[j], j);
        end = clock();
        timer = difftime(end, start) / CLOCKS_PER_SEC;
        fprintf(hashtab_pFile_exp2, "%f\n", timer);

        for (int k = 0; k < 5; k++) {
            num_word = 0 + rand() % (i - 0 + 1);
            start = clock();
            bstree_find = bstree_lookup(tree, word[num_word]);
            end = clock();
            timer = difftime(end, start) / CLOCKS_PER_SEC;
            fprintf(bstree_pFile_exp1, "%f ", timer);

            start = clock();
            hashtab_find = hashtab_lookup(hashtab, pHash, word[num_word]);
            end = clock();
            timer = difftime(end, start) / CLOCKS_PER_SEC;
            fprintf(hashtab_pFile_exp1, "%f ", timer);
        }
        fprintf(bstree_pFile_exp1, "\n");
        fprintf(hashtab_pFile_exp1, "\n");
        bstree_free(tree);
    }
    fclose(bstree_pFile_exp1);
    fclose(hashtab_pFile_exp1);
    printf("Experiment one complete!\n");
}