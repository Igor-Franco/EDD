#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#define TAM 1000

int main()
{
    int v[TAM];
    int i, j, aux;
    srand(time(NULL));
    for (i = 0; i < TAM; i++){
        v[i] = rand() % 101;
        printf ("%i, ", v[i]);
    }
    double time_spent = 0.0;
    clock_t begin = clock ();
    printf("\n");
    int trocas;
    do{
        trocas = 0;
        for (j = 0; j < TAM; j++){
            if (v[j] > v[j+1]){
            aux = v[j];
            v[j] = v[j + 1];
            v[j + 1] = aux;
            trocas = trocas +1;
            }        
        }
    }while (trocas != 0);
    for ( int k = 0; k < TAM; k++){
        printf("%i, ", v[k]); 
        }
    printf("\n");
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n\nTimer: %f\n\n", time_spent);
    return 0;
    
}