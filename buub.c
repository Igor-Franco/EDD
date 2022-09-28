#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
    int tamanho;
    int i;
    tamanho = 10000;
    int array[tamanho]; 
    srand(time(NULL));
    printf("\n");
    for (i = 0; i < tamanho; i++)
    {
        array[i] = rand() % 1000; 
        printf ("%i, ", array[i]);
    }

    double time_spent = 0.0;
    clock_t begin = clock ();


    printf("\n        -----------------------------------\n");

    int k, j, aux;

    for (k = 1; k < tamanho; k++) {
        //printf("\n[%d] ", array[k]);

        for (j = 0; j < tamanho - k; j++) {
            //printf("%d, ", array[j]);

            if (array[j] > array[j + 1]) {
                aux          = array[j];
                array[j]     = array[j + 1];
                array[j + 1] = aux;
            }
        }
    }

    printf("\n");
    for ( i = 0; i < tamanho; i++)
    {
        printf("%d, ", array[i]);
    }
    
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("\n\nTimer: %f\n\n", time_spent);

    return 0;
}