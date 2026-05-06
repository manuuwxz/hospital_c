//Fila circular ********************************************
#include <stdio.h>
 
#define MAX_SIZE 5 // Tamanho máximo da fila (pode alterar)
 
//-1 indicar que a fila tá vazia
int fila[MAX_SIZE]; // Vetor que armazena os elementos
int frente = -1; // Índice do primeiro elemento
int tras = -1; // Índice do último elemento
 
// Verifica se a fila está vazia
int estaVazia() {
    return frente == -1;
}
 
// Verifica se a fila está cheia (versão circular)
int estaCheia() {
    return (frente == (tras + 1) % MAX_SIZE);
}
 
// Enfileirar (enqueue)
void enfileirar(int valor) { //fila[0] = 10 fila[1]=20 fila[2]=30 fila[3]=40 fila[4]=50
 
    if (estaCheia()) {
        printf("Erro: Fila cheia! Não é possível enfileirar %d.\n", valor);
        return;
    }
 
    if (estaVazia()) {
        frente = 0; // Primeira inserção
    }
 
    tras = (tras + 1) % MAX_SIZE;
    fila[tras] = valor;
    printf("Enfileirado: %d\n", valor);
}
 
// Desenfileirar (dequeue) - retorna o valor removido
int desenfileirar(B) {
    if (estaVazia()) {
        printf("Erro: Fila vazia! Nada para desenfileirar.\n");
        return -1; // Valor de erro
}
 
    int valor = fila[frente]; // fila[0] = 10 fila[1]=20
 
    if (frente == tras) {
        // Era o último elemento
        frente = -1;
        tras = -1;
    } else {
        frente = (frente + 1) % MAX_SIZE;
    }
 
    return valor;
}
 
// Consultar o elemento da frente (sem remover)
int consultarFrente() {
    if (estaVazia()) {
        printf("Fila vazia!\n");
        return -1;
    }''
    return fila[frente];
}
 
// Exibir a fila
void exibirFila() {
    if (estaVazia()) {
        printf("Fila vazia!\n");
        return;
    }
 
    printf("Fila: ");
    int i = frente; //pq eu havia tirado dois elementos -- frente=2 pos ou indice, valor do indice, valor da posicao, elemento 
    while (i != tras) {
        printf("%d ", fila[i]);
        i = (i + 1) % MAX_SIZE; //pois usa módulo (resto da divisão) fazer em qualque LP use lista ou vetor
    }
    printf("%d\n", fila[tras]); // imprime o último
}
 
// Programa principal para teste
int main() {
enfileirar(10);
enfileirar(20);
enfileirar(30);
enfileirar(40);
enfileirar(50); // deve encher
 
exibirFila();
 
printf("Desenfileirado: %d\n", desenfileirar());
printf("Desenfileirado: %d\n", desenfileirar());
 
enfileirar(60);
enfileirar(70);
 
exibirFila();
 
printf("Frente da fila: %d\n", consultarFrente());
 
return 0;
}