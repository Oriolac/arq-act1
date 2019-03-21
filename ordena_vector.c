#include <stdio.h>

#define MAX 100

void insertion_sort(int n);
void agafar_nombres(FILE* fitxer_ansi);
int es_primer(int num);

int nombres[MAX];
int primers[MAX];

int main(int argc, int **argv)
{
    FILE * fitxer_ansi;

    fitxer_ansi = fopen("valors.txt", "r");
    agafar_nombres(fitxer_ansi);
    insertion_sort(MAX);
    agafar_primers();

    printf("\n");
    return 1;
}

void agafar_nombres(FILE* fitxer_ansi)
{
    char nombre[3];
    int i;
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

void agafar_primers()
{
    int i, j;
    j = 0;
    for(i = 0; i < MAX; i++)
    {
        if(es_primer(nombres[i]))
        {
            primers[j] = nombres[i];
            j++;
        }
    }
}

int es_primer(int num)
{
    int i;
    i = 2;
    for(i; i < num/2; i++)
    {
        if(num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}