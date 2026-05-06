//Fila circular com ponteiro ****************************************
#include <stdio.h>
#include <stdlib.h>
 
// Estrutura que representa a fila circular
typedef struct {
    int *dados;      // ponteiro para o vetor dinâmico (onde os elementos ficam)
    int frente;      // índice do primeiro elemento da fila
    int tras;        // índice do último elemento inserido
    int tamanho;     // quantidade atual de elementos na fila
    int capacidade;  // tamanho máximo da fila
} Fila;
 
// Função para criar a fila (alocação dinâmica)
Fila* criarFila(int capacidade) {
    // Aloca memória para a estrutura Fila
    Fila *f = (Fila*) malloc(sizeof(Fila));
    
    // Aloca memória para o vetor de dados
    f->dados = (int*) malloc(capacidade * sizeof(int));
    
    // Inicializações
    f->frente = 0;        // começa no índice 0
    f->tras = -1;         // começa em -1 (fila vazia)
    f->tamanho = 0;       // nenhum elemento inicialmente
    f->capacidade = capacidade; // define a capacidade máxima
    
    return f;
}
 
// Verifica se a fila está vazia
int estaVazia(Fila *f) {
    return f->tamanho == 0;
}
 
// Verifica se a fila está cheia
int estaCheia(Fila *f) {
    return f->tamanho == f->capacidade;
}
 
// Função para inserir elemento na fila (enqueue)
void enfileirar(Fila *f, int valor) {
    // Se estiver cheia, não insere
    if (estaCheia(f)) {
        printf("Erro: Fila cheia!\n");
        return;
    }
 
    // Atualiza o índice traseiro de forma circular
    // Se chegar no final do vetor, volta para o início
    f->tras = (f->tras + 1) % f->capacidade;
 
    // Insere o valor na posição calculada
    *(f->dados + f->tras) = valor;
 
    // Incrementa a quantidade de elementos
    f->tamanho++;
 
    printf("Enfileirado: %d\n", valor);
}
 
// Função para remover elemento da fila (dequeue)
int desenfileirar(Fila *f) {
    // Se estiver vazia, não remove
    if (estaVazia(f)) {
        printf("Erro: Fila vazia!\n");
        return -1;
    }
 
    // Captura o valor da frente
    int valor = *(f->dados + f->frente);
 
    // Move a frente de forma circular
    f->frente = (f->frente + 1) % f->capacidade;
 
    // Decrementa o tamanho
    f->tamanho--;
 
    return valor;
}
 
// Função para exibir os elementos da fila
void exibirFila(Fila *f) {
    // Verifica se está vazia
    if (estaVazia(f)) {
        printf("Fila vazia!\n");
        return;
    }
 
    printf("Fila: ");
 
    // Começa pela frente
    int i = f->frente;
 
    // Percorre apenas a quantidade de elementos existentes
    for (int count = 0; count < f->tamanho; count++) {
        // Mostra o valor atual
        printf("%d ", *(f->dados + i));
 
        // Avança de forma circular
        i = (i + 1) % f->capacidade;
    }
 
    printf("\n");
}
 
// Função para liberar memória da fila
void liberarFila(Fila *f) {
    free(f->dados); // libera o vetor
    free(f);        // libera a estrutura
}
 
// Função principal
int main() {
    // Cria uma fila com capacidade 5
    Fila *fila = criarFila(5);
 
    // Inserindo elementos
    enfileirar(fila, 10);
    enfileirar(fila, 20);
    enfileirar(fila, 30);
    enfileirar(fila, 40);
    enfileirar(fila, 50);
 
    // Exibe a fila
    exibirFila(fila);
 
    // Remove dois elementos
    printf("Desenfileirado: %d\n", desenfileirar(fila));
    printf("Desenfileirado: %d\n", desenfileirar(fila));
 
    // Exibe novamente (agora com espaço reutilizado)
    exibirFila(fila);
 
    // Inserindo mais elementos (testando circularidade)
    enfileirar(fila, 60);
    enfileirar(fila, 70);
 
    // Exibe novamente
    exibirFila(fila);
 
    // Libera memória
    liberarFila(fila);
 
    return 0;
}