#include <stdio.h>  
#include <time.h>
#include <stdlib.h>

int getMax(int a[], int n) {  
   int max = a[0];  
   for(int i = 1; i<n; i++) {  
      if(a[i] > max)  
         max = a[i];  
   }  
   return max; //maximum element from the array  
}  
  
void countSort(int a[], int n) // function to perform counting sort  
{  
   int output[n+1];  
   int max = getMax(a, n);  
   int count[max+1]; //create count array with size [max+1]  
  
  
  for (int i = 0; i <= max; ++i)   
  {  
    count[i] = 0; // Initialize count array with all zeros  
  }  
    
  for (int i = 0; i < n; i++) // Store the count of each element  
  {  
    count[a[i]]++;  
  }  
  
   for(int i = 1; i<=max; i++)   
      count[i] += count[i-1]; //find cumulative frequency  
  
  /* This loop will find the index of each element of the original array in count array, and 
   place the elements in output array*/  
  for (int i = n - 1; i >= 0; i--) {  
    output[count[a[i]] - 1] = a[i];  
    count[a[i]]--; // decrease count for same numbers  
}  
  
   for(int i = 0; i<n; i++) {  
      a[i] = output[i]; //store the sorted elements into main array  
   }  
}  
  
void printArr(int a[], int n)
{  
    int i;  
    for (i = 0; i < n; i++)  
        printf("%d ", a[i]);  
}  
  
int main() {  
    int n = 10;  
    int a[n];
    int k;
    for (k = 0; k < n; k++)
    {
        a[k] = rand() % 1001; 
        //printf ("%i, ", a[k]);
    }
    printf("\nAntes do sort os elementos do  array eram - \n");  
    printArr(a, n);  
    
    double time_spent = 0.0;
    clock_t begin = clock ();

    countSort(a, n);  
    printf("\n\nDepois do sort os elentos do array sao - \n");    
    printArr(a, n);  
    printf("\n\n");
    
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("\n\nTimer: %f\n\n", time_spent);

    return 0;  
  
}  