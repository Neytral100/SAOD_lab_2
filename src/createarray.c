#include <stdio.h>
#include <stdlib.h>

void create_array(char** word, int size)
{
    int size_of_word = 21;
    FILE* pFile;
    if ((pFile = fopen("../results/text.txt", "r")) == NULL)
        printf("Error open file\n");
    for (int i = 0; i < size; i++) {
        *(word + i) = malloc(sizeof(char) * size_of_word);
        fgets(*(word + i), size_of_word, pFile);
        for (int j = 0; j < size_of_word; j++)
            if (*(*(word + i) + j * sizeof(char)) == '\n')
                *(*(word + i) + j * sizeof(char)) = 0x0;
    }
    fclose(pFile);
}