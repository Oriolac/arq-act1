#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 100


/* Carregar els valors llegits a un vector de 100 posicions */
void load(int vector[SIZE]){
	FILE *file;
	FILE *fitxer;
	fitxer = fopen("tr_ordena_vector.prg", "w");
	file = fopen("valors.txt", "r");
    int i;
	/* Obrir els fitxers també compta com a instruccio? */

	for(i = 0; i < SIZE; i++){
	fprintf(fitxer, "%d %p \n", 3, &i);

	fprintf(fitxer, "%d %p \n", 2, &i);

		fscanf(file, "%d", &vector[i]);
		fprintf(fitxer, "%d %p \n", 3, &vector[i]);

	fprintf(fitxer, "%d %p \n", 3, &i);
	}

	fclose(file);
	fclose(fitxer);
}


void order (int vector[]){

	FILE *fitxer;
	fitxer = fopen("tr_ordena_vector.prg", "w");
	int i, j;

	fprintf(fitxer, "%d %p \n", 3, &i);
	for (i = 0; i < SIZE-1; i++){

	fprintf(fitxer, "%d %p \n", 2, &i);
		for (j= 0; j < SIZE - i - 1; j++){
		fprintf(fitxer, "%d %p \n", 3, &j);

		fprintf(fitxer, "%d %p \n", 2, &j);
		fprintf(fitxer, "%d %p \n", 2, &i);
			
			fprintf(fitxer, "%d %p \n", 2, &vector[j]);
			fprintf(fitxer, "%d %p \n", 2, &vector[j+1]);
			if(vector[j] > vector[j + 1]){
			

				int aux = vector[j];
				fprintf(fitxer, "%d %p \n", 2, &vector[j]);
				fprintf(fitxer, "%d %p \n", 3, &aux);

                vector[j] = vector[j + 1];
				fprintf(fitxer, "%d %p \n", 2, &vector[j+1]);
				fprintf(fitxer, "%d %p \n", 3, &vector[j]);

                vector[j + 1] = aux;
				fprintf(fitxer, "%d %p \n", 2, &aux);
				fprintf(fitxer, "%d %p \n", 3, &vector[j+1]);
			}

		fprintf(fitxer, "%d %p \n", 3, &j);
		}

	fprintf(fitxer, "%d %p \n", 3, &i);
	}
	fclose(fitxer);
}

bool isPrime (int n) {

	FILE *fitxer;
	fitxer = fopen("tr_ordena_vector.prg", "w");
    int i;
	
	fprintf(fitxer, "%d %p \n", 2, &n);
    if(n == 1){

        return true;
    }
    for(i = 2;  i<= n/2; i++){
	fprintf(fitxer, "%d %p \n", 3, &i);

	fprintf(fitxer, "%d %p \n", 2, &i);
	fprintf(fitxer, "%d %p \n", 2, &n);
	
	fprintf(fitxer, "%d %p \n", 2, &n);
	fprintf(fitxer, "%d %p \n", 2, &i);
        if (n % i == 0){ 

            return false;
        }
	
	fprintf(fitxer, "%d %p \n", 3, &i);
    }
    return true;

	fclose(fitxer);
}


int primeVector ( int vector[], int primes[], int aux) {
	
	FILE *fitxer;
	int i;
    int n = 0;
    
	fitxer = fopen("tr_ordena_vector.prg", "w");

	fprintf(fitxer, "%d %p \n", 3, &n);

	for (i = 0; i < SIZE ; i++){
	fprintf(fitxer, "%d %p \n", 3, &i);

	fprintf(fitxer, "%d %p \n", 2, &i);
	
		fprintf(fitxer, "%d %p \n", 2, &vector[i]);
		fprintf(fitxer, "%d %p \n", 2, &n);
        if(isPrime(vector[i]) && vector[i] > n){

            primes[aux] = vector[i];
			fprintf(fitxer, "%d %p \n", 2, &vector[i]);
			fprintf(fitxer, "%d %p \n", 3, &primes[aux]);

            n = vector[i];
			fprintf(fitxer, "%d %p \n", 2, &vector[i]);
			fprintf(fitxer, "%d %p \n", 3, &n);

			aux++;
			fprintf(fitxer, "%d %p \n", 3, &aux);
        }
	
	fprintf(fitxer, "%d %p \n", 3, &i);
    }

	fclose(fitxer);

	return aux;
}


void encripta (int vector[], int aux, int resultat[]){

	FILE *fitxer;
    int i;
	fitxer = fopen("tr_ordena_vector.prg", "w");

	for(i = 0; i < (aux/2) + 1; i++){
	fprintf(fitxer, "%d %p \n", 3, &i);

	fprintf(fitxer, "%d %p \n", 2, &i);
	fprintf(fitxer, "%d %p \n", 2, &aux);

		resultat[i] = vector[i] * vector[aux - 1 - i];
		fprintf(fitxer, "%d %p \n", 2, &vector[i]);
		fprintf(fitxer, "%d %p \n", 2, &vector[aux-1-i]);
		fprintf(fitxer, "%d %p \n", 3, &resultat[i]);
	
	fprintf(fitxer, "%d %p \n", 3, &i);
	}

	fclose(fitxer);
}

void print (int vector[], int n){

	FILE *fitxer;
    int i;
	fitxer = fopen("tr_ordena_vector.prg", "w");

	for (i = 0 ; i < n; i++){
	fprintf(fitxer, "%d %p \n", 3, &i);

	fprintf(fitxer, "%d %p \n", 2, &i);
	fprintf(fitxer, "%d %p \n", 2, &n);

		printf("%i ", vector[i]);
		fprintf(fitxer, "%d %p \n", 2, &vector[i]);

	fprintf(fitxer, "%d %p \n", 3, &i);
	}
	printf("\n");
	printf("\n");

	fclose(fitxer);
}


int main(){

	FILE *fitxer;
	fitxer = fopen("tr_ordena_vector.prg", "w");

	int vector [SIZE];
	int primes [SIZE];
	int aux = 0;
	fprintf(fitxer, "%d %p \n", 3, &aux);

	load(vector);
	order(vector);
    printf("Vector ordenat: \n");
	print(vector, SIZE);
	
	aux = primeVector(vector, primes, aux);
    printf("Vector ordenat de nombes primers: \n");
    print(primes, aux);

	int len_encriptat;

	fprintf(fitxer, "%d %p \n", 2, &aux);
	if(aux % 2 == 0){

		len_encriptat = aux / 2;
		fprintf(fitxer, "%d %p \n", 2, &aux);
		fprintf(fitxer, "%d %p \n", 3, &len_encriptat);

	}else{
		len_encriptat = (aux / 2) + 1;
		fprintf(fitxer, "%d %p \n", 2, &aux);
		fprintf(fitxer, "%d %p \n", 3, &len_encriptat);
	}
	
	int encriptat [len_encriptat];
	encripta(primes, aux, encriptat);
	printf("Vector encriptat: \n");
	print(encriptat, len_encriptat);
	fclose(fitxer);
}