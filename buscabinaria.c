//Aluno: Igor Ferreira Franco SP3099695
#include <stdio.h>
#include <stdlib.h>

#define N 10

int v[N] = {3,35,58,60,89,92,99,100,131,148};
int e = 0; //Limite inferior (esquerda)
int d = N -1; //Limite superior (direita)

int buscaBinaria (int x, int v[], int e, int d)
{
 int meio = (e + d)/2;
 if (v[meio] == x)
    return meio;
 if (e >= d)
    return -1; // não encontrado
 else
     if (v[meio] < x)
        return buscaBinaria(x, v, meio+1, d);
     else
        return buscaBinaria(x, v, e, meio-1);
}
void printArr(int v[])
{  
    int i;  
    for (i = 0; i < N; i++)  
        printf("%d ", v[i]);  
}  

int main()
{
printf("v[N] :");
printArr(v);
int x; //Numero do array que deseja buscar
printf("\nQuan numero deseja busca:");
scanf("%i", &x);
int busca = buscaBinaria(x, v, e, d);
if (busca == -1){
    printf("Numero nao encontrado\n");
}else{ 
    printf("\nIndice: %d\n", busca + 1);
}

return 0;
}