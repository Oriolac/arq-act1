#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void insertion_sort(int n);
void agafar_nombres(FILE* fitxer_ansi);
int agafar_primers();
int es_primer(int num);
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
    fprintf(fitxer, "%d %p", 2, &i);
    fprintf(fitxer, "%d %p", 3, &i);
    for(i = 0; i < MAX; i++)
    {
        fscanf(fitxer_ansi, "%s", nombre);
        nombres[i] = atoi(nombre);
    }

}

void insertion_sort(int n)
{
    int i, key, j;
    for(i = 1; i < n; i++)
    {
        key = nombres[i];
        j = i - 1;
        while(j >= 0 && nombres[j] > key)
        {
            nombres[j+1] = nombres[j];
            j--; 
        }
        nombres[j+1] = key;
    }
}

int agafar_primers()
{
    int i, j;
    j = 0;
    for(i = 0; i < MAX; i++)
    {
        if((j == 0 || nombres[i] != primers[j-1]) && es_primer(nombres[i]))
        {
            primers[j] = nombres[i];
            j++;
        }
    }
    return j;
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
    for(i = 0; i < num_max; i++)
    {
        clau_cripto[i] = primers[i] * primers[num_max - i -1];
    }
}

void show(int num_max, int numbers[])
{
    int i;
    for(i = 0; i < num_max; i++)
    {
        printf("%i ", numbers[i]);
    }
    printf("\n");
}