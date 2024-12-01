#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

//Inicializa a nova fila
void inicializarFila(Fila *fila){
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}

//Insere um elemento no FINAL da fila
void inserirFila(Fila *fila, int idade){
    Node *novo = (Node *)malloc(sizeof(Node));
    if (!novo){
        perror("erro na memoria");
        exit(EXIT_FAILURE);
    }
    novo->idade = idade;
    novo->prev = fila->fim;
    novo->next = NULL;

    if (fila->fim){
        fila->fim->next = novo;
    }
    fila->fim = novo;

    if (!fila->inicio){
        fila->inicio = novo;
    }
    fila->tamanho++;
}

//Remove o elemento do INÍCIO da fila
int removerFila(Fila *fila){
    if (fila->tamanho == 0){
        fprintf(stderr, "fila vazia\n");
        return -1;
    }

    Node *remover = fila->inicio;
    int idade = remover->idade;

    fila->inicio = remover->next;
    if (fila->inicio){
        fila->inicio->prev = NULL;
    } else {
        fila->fim = NULL;
    }

    free(remover);
    fila->tamanho--;
    return idade;
}

//Ordena a fila com BUBBLE SORT (maior para menor)
void ordenarFila(Fila *fila){
    if (!fila->inicio || fila->tamanho < 2) return; //Retorna um erro caso a fila esteja vazia ou com menos de 2 itens

    int trocado;
    Node *atual;

    do{
        trocado = 0;
        atual = fila->inicio;

        while (atual->next){                            //Vai até o penúltimo nó
            if (atual->idade < atual->next->idade){     //Ordem decrescente e troca de idades
                int temp = atual->idade;
                atual->idade = atual->next->idade;
                atual->next->idade = temp;
                trocado = 1;                            //Indica troca
            }
            atual = atual->next;
        }
    } while (trocado);
}

//Libera a memória alocada
void liberarFila(Fila *fila){
    Node *atual = fila->inicio;
    while (atual){
        Node *proximo = atual->next;
        free(atual);
        atual = proximo;
    }
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}

//Mostra a fila
void exibirFila(Fila *fila){
    Node *atual = fila->inicio;
    printf("Fila: ");
    while (atual){
        printf("%d ", atual->idade);
        atual = atual->next;
    }
    printf("\n");
}