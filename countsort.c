#include <stdio.h>  
#include <time.h>
#include <stdlib.h>

int getMax(int a[], int n) {  
   int max = a[0];  
   for(int i = 1; i<n; i++) {  
      if(a[i] > max)  
         max = a[i];  
   }  
   return max; 
}  
  
void countSort(int a[], int n) 
{  
   int output[n+1];  
   int max = getMax(a, n);  
   int count[max+1];
  
  
  for (int i = 0; i <= max; ++i)   
  {  
    count[i] = 0;
  }  
    
  for (int i = 0; i < n; i++)
  {  
    count[a[i]]++;  
  }  
  
   for(int i = 1; i<=max; i++)   
      count[i] += count[i-1];
  for (int i = n - 1; i >= 0; i--) {  
    output[count[a[i]] - 1] = a[i];  
    count[a[i]]--;
}  
  
   for(int i = 0; i<n; i++) {  
      a[i] = output[i];
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
    for (k = 0; k < n; k++){
        a[k] = rand() % 1001; 
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