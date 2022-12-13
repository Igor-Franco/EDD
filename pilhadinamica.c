/*
Aluno: Igor Ferreira Franco SP3099695;
Desafio: desenvolver uma pilha dinamica com HEAD(Topo, base e quantidade).
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no{
    int dado;
    struct no * prox;
}no;

/*Parte estrutural:
Precisa de uma estrutura, que aponta para o dado atual (topo da pilha);
Precisa de um ponteiro que aponta para o proximo dado da pilha;
Ao iniciar o primeiro No aponta para NULL para identificar a base da pilha;
Precisa da funcao free para liberar o espaco de memoria apos um pop ou destruicao da pilha.
*/

// Parte comportamental:
no * criar(void);// criar pilha;
// Colocar e trirar dados da pilha:
void push(no * cabeca, int val);//Adicionar dados a pilha;
int  pilhapop (no * cabeca);//testar se pilha esta vazia, tirar dados da pilha, liberar espeaco da memoria e apresenta-los;
// destrui pilha:
void destroi(no * * pilha);//Destruir pilha e liberar os espacos da memoria;
// imprimir dados da pilha e cabecalho:
void imprimir(no * pilha);// imprimir a pilha;
int  head(no * pilha, int cont);// mostrar o topo e o numero de dados na pilha;

int main(void)
{	
    no * pilha = criar();
    int prompt, contador, cont, i;
	do{
        do{
            cont = head(pilha, cont);
            printf("\nNumero de itens: %d\nPressione: push(1), pop(2), Imprimir(3), Destruir(0): ", cont);
            scanf("%d", &prompt);        
        } while ( prompt <0 || prompt > 3);

        if(prompt == 1){    
            printf("Quantos inteiros deseja adiciona? ");
            scanf("%d", &contador);
            for (i = 0; i < contador; i++){
                int inteiro = rand() %101;
                push(pilha, inteiro);
            }
            printf("\n");
        } else if (prompt == 2){
            printf("Quantos inteiros deseja remover? ");
            scanf("%d", &contador);
            for (i = 0; i < contador; i++){
                int pop = pilhapop(pilha);
                if (pop == -1)
                {
                    printf("ERRO: pilha vazia!\n");
                } else
                {
                printf("Pop: %d; ", pop);
                }
            }
            printf("\n");
            contador = 0;
        } else if(prompt == 3){
            printf("[Topo]:");
            imprimir(pilha);
            printf("\n");
        } else if(prompt == 0){
            destroi(&pilha);
            prompt = -1;
        }
    } while (prompt != -1);
    return 0;

}

no * criar(void){
    no * cabeca = malloc(sizeof(no));
    cabeca -> prox = NULL; 
    return cabeca;    
}

void push(no * cabeca, int val){
    if(cabeca){
        no * novo_no = malloc(sizeof(no));
        novo_no->dado = val;
        novo_no->prox = cabeca->prox;
        cabeca->prox = novo_no;
    }
}

int pilhapop (no * cabeca){
    if (cabeca){
        no * seguinte = cabeca->prox;
        if(seguinte){
            int val = seguinte->dado;
            cabeca->prox = seguinte->prox;
            free(seguinte);
            return val;
        }
    }
    return -1;
}

void destroi(no * * pilha){
    no * aux = * pilha;
    no * temp;
    while (aux){
       temp = aux;
       aux = aux->prox;
       free(temp);
    }
    *pilha = NULL;
}

void imprimir(no * pilha){
    pilha = pilha->prox;
    while (pilha){
        printf("[%d],", pilha->dado);
        pilha = pilha->prox;

    }
    printf("[BASE]\n");
}

int head(no * pilha, int cont){
    int con = 0;
    int a = 0;
    pilha = pilha->prox;
    while (pilha){
        if(a == 0){
            printf("Topo = [%d]", pilha->dado);
        } else if (pilha->prox == NULL){
            printf("Base = [%d]", pilha->dado);
        }
        
        pilha = pilha->prox;
        a++;
        con++;
    }
    return con;
}