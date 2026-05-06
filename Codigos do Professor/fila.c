//FILA***********************************************
#include <stdio.h>
 
#define MAX_SIZE 5 
 
int fila[MAX_SIZE];  
int frente = 0; // Inicia em 0 na linear
int tras = -1; 
 
// Verifica se a fila está vazia
int estaVazia() {
    return frente > tras;
}
 
// Verifica se a fila está cheia (limite do vetor)
int estaCheia() {
    return tras == MAX_SIZE - 1;
}
 
// Enfileirar (enqueue)
void enfileirar(int valor) {
    if (estaCheia()) {
        printf("Erro: Fila linear cheia! (Limite do vetor atingido)\n");
        return;
    }
    tras++; 
    fila[tras] = valor;
    printf("Enfileirado: %d\n", valor);
}
 
// Desenfileirar (dequeue)
int desenfileirar() {
    if (estaVazia()) {
        printf("Erro: Fila vazia!\n");
        return -1;
    }
    int valor = fila[frente]; 
    frente++; // Simplesmente avança a frente
    return valor;
}
 
// Exibir a fila
void exibirFila() {
    if (estaVazia()) {
        printf("Fila vazia!\n");
        return;
    }
    printf("Fila: ");
    for (int i = frente; i <= tras; i++) {
        printf("%d ", fila[i]);
    }
    printf("\n");
}
 
int main() {
    enfileirar(10);//chamando a funcão
    enfileirar(20);
    enfileirar(30);
    
    exibirFila();
 
    printf("Desenfileirado: %d\n", desenfileirar());
    
    exibirFila(); // Note que o espaço do '10' agora está "perdido"
 
    return 0;
}