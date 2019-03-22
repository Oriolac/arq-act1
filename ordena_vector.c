#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void insertion_sort(int n);
void agafar_nombres(FILE* fitxer_ansi);
int agafar_primers();
int es_primer(int num);
int mirar_anterior(int i, int j);
int equal_to_0(int j);
void claus_criptografiques(int num_max);
void show(int num, int numbers[]);

int nombres[MAX];
int primers[MAX];
int clau_cripto[MAX];
FILE* fitxer;

int main(int argc, char **argv)
{
    FILE * fitxer_ansi;
    int num_primers;

    fitxer_ansi = fopen("valors.txt", "r");
    fitxer = fopen("tr_ordena_vector.prg", "w");

    agafar_nombres(fitxer_ansi);
    fclose(fitxer_ansi);
    insertion_sort(MAX);
    num_primers = agafar_primers();
    fprintf(fitxer, "%d %p\n", 3, &num_primers);
    claus_criptografiques(num_primers);
    printf("Vector ordenat:\n");
    show(MAX, nombres);
    printf("\nVector de nombres primers:\n");
    show(num_primers, primers);
    printf("\nVector de claus criptogràfiques:\n");
    show(num_primers, clau_cripto);

    printf("\n");
    return 1;
}

void agafar_nombres(FILE* fitxer_ansi)
{
    char nombre[4];
    int i;
    fprintf(fitxer, "%d %p\n", 3, &i);
    fprintf(fitxer, "%d %p\n", 2, &i);
    fprintf(fitxer, "%d %p\n", 2, &i);
    for(i = 0; i < MAX; i++)
    {
        fscanf(fitxer_ansi, "%s", nombre);
        fprintf(fitxer, "%d %p\n", 3, &nombre);
        nombres[i] = atoi(nombre);
        fprintf(fitxer, "%d %p\n", 2, &nombre);
        fprintf(fitxer, "%d %p\n", 2, &i);
        fprintf(fitxer, "%d %p\n", 3, &nombres[i]);

        fprintf(fitxer, "%d %p\n", 2, &i);
        fprintf(fitxer, "%d %p\n", 3, &i);
        fprintf(fitxer, "%d %p\n", 2, &i);
    }

}

void insertion_sort(int n)
{
    int i, key, j;

    fprintf(fitxer, "%d %p\n", 3, &i);
    fprintf(fitxer, "%d %p\n", 2, &i);
    fprintf(fitxer, "%d %p\n", 2, &n);
    for(i = 1; i < n; i++)
    {
        key = nombres[i];
        fprintf(fitxer, "%d %p\n", 3, &key);
        fprintf(fitxer, "%d %p\n", 2, &i);
        fprintf(fitxer, "%d %p\n", 2, &nombres[i]);


        j = i - 1;
        fprintf(fitxer, "%d %p\n", 2, &i);
        fprintf(fitxer, "%d %p\n", 3, &j);
        fprintf(fitxer, "%d %p\n", 2, &j);

        fprintf(fitxer, "%d %p\n", 2, &j);
        fprintf(fitxer, "%d %p\n", 2, &nombres[j]);
        fprintf(fitxer, "%d %p\n", 2, &key);
        while(j >= 0 && nombres[j] > key)
        {
            nombres[j+1] = nombres[j];
            fprintf(fitxer, "%d %p\n", 2, &j);
            fprintf(fitxer, "%d %p\n", 2, &nombres[j]);
            fprintf(fitxer, "%d %p\n", 2, &j);
            fprintf(fitxer, "%d %p\n", 3, &nombres[j+1]);

            j--;
            fprintf(fitxer, "%d %p\n", 2, &j);
            fprintf(fitxer, "%d %p\n", 3, &j);

            fprintf(fitxer, "%d %p\n", 2, &j);
            fprintf(fitxer, "%d %p\n", 2, &nombres[j]);
            fprintf(fitxer, "%d %p\n", 2, &key);
        }
        nombres[j+1] = key;
        fprintf(fitxer, "%d %p\n", 2, &key);
        fprintf(fitxer, "%d %p\n", 2, &j);
        fprintf(fitxer, "%d %p\n", 3, &nombres[j+1]);

        fprintf(fitxer, "%d %p\n", 2, &i);
        fprintf(fitxer, "%d %p\n", 3, &i);
        fprintf(fitxer, "%d %p\n", 2, &n);
    }
}

int agafar_primers()
{
    int i, j;
    j = 0;
    fprintf(fitxer, "%d %p\n", 3, &j);

    fprintf(fitxer, "%d %p\n", 3, &i);
    for(i = 0; i < MAX; i++)
    {
        if((equal_to_0(j) || mirar_anterior(i, j)) && es_primer(nombres[i]))
        {
            primers[j] = nombres[i];
            fprintf(fitxer, "%d %p\n", 2, &nombres[i]);
            fprintf(fitxer, "%d %p\n", 3, &primers[i]);
            j++;
            fprintf(fitxer, "%d %p\n", 2, &j);
            fprintf(fitxer, "%d %p\n", 3, &j);

        }

        fprintf(fitxer, "%d %p\n", 2, &i);
    }
    return j;
    fprintf(fitxer, "%d %p\n", 2, &j);
}

int mirar_anterior(int i, int j)
{
    fprintf(fitxer, "%d %p\n", 2, &j);
    fprintf(fitxer, "%d %p\n", 2, &i);
    fprintf(fitxer, "%d %p\n", 2, &primers[j-1]);
    fprintf(fitxer, "%d %p\n", 2, &nombres[i]);
    return nombres[i] != primers[j-1];
}

int equal_to_0(int j)
{
    fprintf(fitxer, "%d %p\n", 2, &j);
    return j == 0;
}

int es_primer(int num)
{
    int i;
    for(i= 2; i < num/2 + 1; i++)
    {
        if(num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

void claus_criptografiques(int num_max)
{
    int i;
    fprintf(fitxer, "%d %p\n", 3, &i);
    fprintf(fitxer, "%d %p\n", 2, &num_max);
    for(i = 0; i < num_max; i++)
    {
        clau_cripto[i] = primers[i] * primers[num_max - i - 1];
        fprintf(fitxer, "%d %p\n", 2, &i);
        fprintf(fitxer, "%d %p\n", 2, &num_max);
        fprintf(fitxer, "%d %p\n", 2, &primers[num_max - i - 1]);
        fprintf(fitxer, "%d %p\n", 2, &primers[i]);
        fprintf(fitxer, "%d %p\n", 2, &clau_cripto[i]);



        fprintf(fitxer, "%d %p\n", 2, &i);
        fprintf(fitxer, "%d %p\n", 3, &i);
        fprintf(fitxer, "%d %p\n", 2, &num_max);
    }
}

void show(int num_max, int numbers[])
{
    int i;
    fprintf(fitxer, "%d %p\n", 3, &i);
    fprintf(fitxer, "%d %p\n", 2, &num_max);
    for(i = 0; i < num_max; i++)
    {
        printf("%i ", numbers[i]);
        fprintf(fitxer, "%d %p\n", 2, &i);
        fprintf(fitxer, "%d %p\n", 2, &numbers[i]);

        fprintf(fitxer, "%d %p\n", 2, &i);
        fprintf(fitxer, "%d %p\n", 3, &i);
        fprintf(fitxer, "%d %p\n", 2, &num_max);
    }
    printf("\n");
}