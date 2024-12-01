#ifndef FILA_H
#define FILA_H

//Estrutura de Nós da lista
typedef struct Node {
    int idade;              //Idade do cliente
    struct Node *prev;      //Ponteiro para o nó anterior
    struct Node *next;      //Ponteiro para o próximo nó
} Node;

//Estrutura do TAD da fila
typedef struct Fila {
    int tamanho;            //Ponteiro para o início da fila
    Node *inicio;           //Ponteiro para o fim da fila
    Node *fim;              //Tamanho atual da fila
} Fila;

/*
 Inicializa uma nova fila vazia
 Exemplo de uso:
   Fila minhaFila;
   inicializarFila(&minhaFila);
   // minhaFila está pronta para uso com tamanho 0 e ponteiros NULL
 */
void inicializarFila(Fila *fila);

/*
 Insere um novo cliente no final da fila
 Parâmetros:
   fila: ponteiro para a fila
   idade: idade do cliente a ser inserido
 Exemplo de uso:
   inserirFila(&minhaFila, 65);
   inserirFila(&minhaFila, 70);
   // Fila agora contém dois clientes: 65, 70
 */
void inserirFila(Fila *fila, int idade);

/*
 Remove e retorna a idade do cliente no início da fila
 Retorna: idade do cliente removido ou -1 se a fila estiver vazia
 Exemplo de uso:
   int idadeCliente = removerFila(&minhaFila);
   if (idadeCliente != -1) {
       printf("Cliente com idade %d foi atendido\n", idadeCliente);
   }
 */
int removerFila(Fila *fila);

/*
 Ordena a fila usando Bubble Sort (do maior para o menor)
 Exemplo de uso:
   // Fila com idades: 65, 80, 70
   ordenarFila(&minhaFila);
   // Fila ordenada: 80, 70, 65
 */
void ordenarFila(Fila *fila);

/*
 Libera toda a memória alocada pela fila
 Exemplo de uso:
   // Após terminar de usar a fila
   liberarFila(&minhaFila);
   // Toda memória foi liberada, fila não pode mais ser usada
 */
void liberarFila(Fila *fila);

/*
 Exibe todos os elementos da fila
 Exemplo de uso:
   // Para visualizar a fila atual
   exibirFila(&minhaFila);
   // Saída: Fila: 80 -> 70 -> 65
 */
void exibirFila(Fila *fila);

#endif