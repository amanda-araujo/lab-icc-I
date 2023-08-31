#include <stdio.h>
#include <stdlib.h>

#define SIZE_FILE_NAME 100

int count_word(char *filename);

int main()
{
    char filename_orig[SIZE_FILE_NAME], filename_test[SIZE_FILE_NAME];
    int counter_orig, counter_test, per_cent;

    scanf("%s\n", filename_orig);
    scanf("%s", filename_test);

    counter_orig = count_word(filename_orig);
    counter_test = count_word(filename_test);
    per_cent = 100*counter_test/counter_orig;

    printf("O candidato digitou %d de %d palavras (%d%%).\n",
                              counter_test, counter_orig, per_cent);
    
    if (per_cent >= 20)
    {
        printf("Parabéns, candidato! Você foi aprovado!\n");
    }
    else
    {
        printf("Lamentamos informar, mas você não cumpre os requisitos da vaga, candidato!\n");
    }

    return 0;
}


int count_word(char *filename)
{
    int counter = 0;
    int prev_charac = 0; //charac, 
    char charac;
    FILE *file;

    file = fopen(filename, "r");

    if (file != NULL)
    {
        while (fscanf(file, "%c", &charac) != EOF)
        {
            if (  ( charac != 10 && charac != 32 && charac != 0 ) &&
                  ( prev_charac == 10 || prev_charac == 32 || prev_charac == 0 ) )
            {
                counter++;
            }

            prev_charac = charac;
        }
    }

    fclose(file);

    return counter;
}
