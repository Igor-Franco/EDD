#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXFILA 100


typedef struct fila
{
    int dados[MAXFILA];
    int comeco;
    int final;
    int total;
}fila;

void qinit(fila *p){
    p->total = 0;
    p->comeco = 0;
    p->final = 0;
}

int qisempty (fila *p){
    if (p->total == 0)
    {
        return -2;
    } else
    {
        return 0;
    }  
}

int qisfull (fila *p){
    if (p->total == MAXFILA -1)
    {
        return -1;
    } else
    {
        return 0;
    }
}

int adc(fila *p, int ind){
    ind ++;
    if (ind > MAXFILA -1)
    {
        ind = 0;
    }
    return ind;
}

void enqueue (fila *p, int dado){
    if (qisfull(p) == -1)
    {
        printf("ERRO: pilha cheira!\n");
    } else
    {
        p->dados[p->final] = dado;
        p->final = adc(p, p->final);
        p->total++;
    }
}

int dequeue(fila *p){
    int dadofila;
    if (qisempty(p) == -2)
    {
        printf("ERRO: pilha vazia ao tentar desinfileirar!\n");
    } else
    {
       dadofila = p->dados[p->comeco];
       p->comeco = adc(p, p->comeco);
       p->total--;
       return dadofila;
    }
    return 0;
}

int prompt(fila *p, int aux, int ind){
    do{
    printf("Tamanho fila: %d\nComeco:[%d]\n Final: %d\n Total: %d\n", MAXFILA -1, p->dados[p->comeco],p->dados[p->final], p->total);
    printf("Pression: Enqueue(1) Dequeue(2) Sair(0)");
    scanf("%d", &aux);
    return aux;
    } while(aux > 0 || aux < 2);
    
}   

int main(void)
{
    int ind;
    fila *p = (fila*)malloc(sizeof(fila));
    int indice = adc(p, ind);
    qinit(p);
    int aux, i;
    do
    {
        aux = prompt(p, aux, ind);
        if (aux == 1)//enqueue
        {
            int count;
            printf("Quantos itens deseja inserir:\n");
            scanf("%d", &count);
            for (i = 0; i < count; i++)
            {
                int dado = rand()%1001;
                enqueue(p, dado);
            }
        } else if (aux == 2)//dequeue
        {
            int count;
            printf("Quantos itens deseja retirar:\n");
            scanf("%d", &count);
            for (i = 0; i < count; i++)
            {
                int dadofila = dequeue(p/*, p->dados*/);
                printf("Saiu: %d, ", dadofila);
            }
            printf("\n");
        printf("\n");
        }
    } while (aux != 0);
    


    return 0;
}