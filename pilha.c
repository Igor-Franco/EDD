#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 101

typedef struct
{
    int item[TAM];
    int topo;
}tpilha;

void inicia (tpilha *p){
    p->topo = 0;
}

int vazia (tpilha *p){
    if (p->topo == -1)
    {
        return 1;
    }else {
        return 0;
    }   
}

int cheia (tpilha *p){
    if (p->topo == TAM -1)
    {
        return 1;
    } else {
        return 0;
    }
}

void push (tpilha *p, int a[], int i){
    if (cheia(p) == 1)
    {
        printf("ERRO: Pilha cheia");
    } else{
        p-> topo++;
        p-> item[p->topo] = a[i];
    }
}
int pop (tpilha *p){
    int aux;
    if (vazia(p) == 1)
    {
        printf("ERRO: Pilha vazia");
    } else{
        aux = p-> item[p->topo];
        p->topo--;
        return aux;
    }
    return 0;
}

int prompt (tpilha *p){
    int resposta;
    printf("\n\nTamanho maximo: 100\nTopo: [%d]\nItens: %d",p->item[p->topo], p->topo);

    do
    {
        printf("\n Pressione: Push(1), Pop(2), Listar(3), Finalizar (0)");
        scanf("%d", &resposta);    
    } while (resposta > 3 || resposta < 0);
    return resposta;
}
int main(void)
{
    tpilha *p = (tpilha*)malloc(sizeof(tpilha));
    inicia (p);
        int resp;
        int num;
    do{
        resp = prompt(p);
        int a[TAM];
        if ( resp == 1)
        {
            printf ("\nQuantos inteiros deseja inserir:");
            scanf("%d", &num);
            int i;
            for(i = 0; i < num; i++)
            {
                a[i] = rand() % 1001;
                push (p, a, i);
            }
        }else if (resp == 2)
        {
            printf("\nQuantos inteiros deseja remover:");
            scanf("%d", &num);
            int aux, i;
            for (i = 0; i < num; i++)
            {
            aux = pop(p);
            //printf("saiu: %d ", aux); PARA VER ITEM QUE SAIU. 
            }           
        }else if (resp == 3)
        {
            int j;
            printf("\n Lista: ");
            for(j=0 ;j<= p->topo;j++){
                if(p->item[j]!=0){
                printf("%i, ",p->item[j]);
            }
            }
        }
    }while(resp != 0);
    printf("\n");
    return 0;
}