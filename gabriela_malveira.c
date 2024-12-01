#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(){
    Fila filaPrioridade;
    inicializarFila(&filaPrioridade);

    //Abrindo o arquivo "clientes.txt"
    FILE *arquivo = fopen("clientes.txt", "r");
    if (!arquivo){
        perror("Erro ao abrir");
        return 1;
    }

    printf("Iniciando leitura do arquivo de clientes...\n");
    int idade;
    while (fscanf(arquivo, "%d", &idade) == 1){
        printf("Cliente com idade %d adicionado a fila\n", idade);
        inserirFila(&filaPrioridade, idade);
    }
    fclose(arquivo);
    printf("\n");

    printf("\nIniciando ordenacao da fila por prioridade...\n");
    ordenarFila(&filaPrioridade);
    printf("Ordenacao concluida!\n\n");

    printf("Iniciando atendimento:\n");
    while (filaPrioridade.tamanho > 0){
        int atendido = removerFila(&filaPrioridade);
        printf("Atendendo clientes com idade: %d\n", atendido);
    }

    liberarFila(&filaPrioridade);
    return 0;    
}