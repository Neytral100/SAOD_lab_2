#include "createarray.h"
#include "hashtab.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void experiment_two()
{
    clock_t start, end;
    float timer;
    int num_word;
    int collision_KR = 0;
    int collision_ELF = 0;

    struct listnode* hashtab_KR[HASHTAB_SIZE];
    struct listnode* hashtab_ELF[HASHTAB_SIZE];
    struct listnode* hashtab_find;
    FILE* pFile_KR;
    FILE* pFile_ELF;

    int size = 200000;
    char* word[size];
    create_array(word, size);

    if ((pFile_KR = fopen("../results/hashtabKR.txt", "w")) == NULL)
        printf("Error open file hashtabKR.txt\n");
    if ((pFile_ELF = fopen("../results/hashtabELF.txt", "w")) == NULL)
        printf("Error open file hashtabELF.txt\n");

    srand(time(NULL));

    for (int i = 10000; i <= size; i += 10000) {
        collision_KR = 0;
        collision_ELF = 0;
        printf("%d ", i);
        fprintf(pFile_KR, "%d ", i);
        fprintf(pFile_ELF, "%d ", i);

        hashtab_init(hashtab_KR);
        hashtab_init(hashtab_ELF);

        for (int j = 1; j < i; j++) {
            collision_KR += hashtab_add(hashtab_KR, KRhash, word[j], j);
            collision_ELF += hashtab_add(hashtab_KR, ELFhash, word[j], j);
        }

        for (int k = 0; k < 5; k++) {
            num_word = 0 + rand() % (i - 0 + 1);
            printf("%s ", word[num_word]);
            start = clock();
            hashtab_find = hashtab_lookup(hashtab, KRhash, word[num_word]);
            end = clock();
            timer = difftime(end, start) / CLOCKS_PER_SEC;
            fprintf(pFile_KR, "%f ", timer);

            start = clock();
            hashtab_find = hashtab_lookup(hashtab, ELFhash, word[num_word]);
            end = clock();
            timer = difftime(end, start) / CLOCKS_PER_SEC;
            fprintf(pFile_ELF, "%f ", timer);
        }
        printf("\n");
        fprintf(pFile_ELF, "%d", collision_ELF);
        fprintf(pFile_KR, "%d", collision_KR);
        fprintf(pFile_ELF, "\n");
        fprintf(pFile_KR, "\n");
    }

    fclose(pFile_ELF);
    fclose(pFile_KR);
    printf("Experiment two complete!\n");
}