#include <stdio.h>

#define MAX 100

void insertion_sort(int n);

int nombres[MAX];

int main(int argc, int **argv)
{
    FILE * fitxer_ansi;
    char nombre[3];
    int i;

    fitxer_ansi = fopen("valors.txt", "r");

    for(i = 0; i < MAX; i++)
    {
        fscanf(fitxer_ansi, "%s", nombre);
        nombres[i] = atoi(nombre);
    }
    printf("Holaa\n");
    insertion_sort(MAX);
    printf("Holaahhhh\n");
    for(i = 0; i < MAX; i++){
        printf("%i, ", nombres[i]);
    }
    printf("\n");
    return 1;
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