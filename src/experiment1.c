#include "bstree.h"
#include "hashtab.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void create_array(char** word, int size)
{
    int size_of_word = 21;
    FILE* pFile;
    if ((pFile = fopen("../results/text.txt", "r")) == NULL)
        printf("Не удалось открыть файл\n");
    for (int i = 0; i < size; i++) {
        *(word + i) = malloc(sizeof(char) * size_of_word);
        fgets(*(word + i), size_of_word, pFile);
        for (int j = 0; j < size_of_word; j++)
            if (*(*(word + i) + j * sizeof(char)) == '\n')
                *(*(word + i) + j * sizeof(char)) = 0x0;
    }
    fclose(pFile);
}

void experiment_one()
{
    clock_t start, end;
    float timer;
    int num_word;
    struct bstree* bstree_find;
    struct listnode* hashtab_find;
    int size = 200000;
    char* word[size];
    create_array(word, size);
    FILE* bstree_pFile;
    FILE* hashtab_pFile;
    srand(time(NULL));
    if ((bstree_pFile = fopen("../results/bstree1.txt", "w")) == NULL)
        printf("Не удалось открыть файл\n");
    if ((hashtab_pFile = fopen("../results/hashtab1.txt", "w")) == NULL)
        printf("Не удалось открыть файл\n");
    for (int i = 10000; i <= size; i += 10000) {
        fprintf(bstree_pFile, "%d ", i);
        fprintf(hashtab_pFile, "%d ", i);
        struct bstree* tree;
        tree = bstree_create(word[0], 0);
        hashtab_init(hashtab);
        for (int j = 1; j < i; j++) {
            bstree_add(tree, word[j], j);
            hashtab_add(hashtab, word[j], j);
        }

        for (int k = 0; k < 5; k++) {
            num_word = 0 + rand() % (i - 0 + 1);
            start = clock();
            bstree_find = bstree_lookup(tree, word[num_word]);
            end = clock();
            timer = difftime(end, start) / CLOCKS_PER_SEC;
            fprintf(bstree_pFile, "%f ", timer);

            start = clock();
            hashtab_find = hashtab_lookup(hashtab, word[num_word]);
            end = clock();
            timer = difftime(end, start) / CLOCKS_PER_SEC;
            fprintf(hashtab_pFile, "%f ", timer);
        }
        fprintf(bstree_pFile, "\n");
        fprintf(hashtab_pFile, "\n");
        bstree_free(tree);
    }
    fclose(bstree_pFile);
    fclose(hashtab_pFile);
    printf("Experiment one complete!\n");
}