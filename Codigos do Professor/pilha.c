//Pilha *****************************************
#include <stdio.h>
#define MAX 100
 
int pilha[MAX];// vetor que representa a pilha
int topo = -1; // controla o topo da pilha
 
// Função para empilhar (push)
void empilhar(int valor) {
    if (topo == MAX - 1) {
        printf("Erro: Pilha cheia!\n");
        return;
    }
    topo++;
    pilha[topo] = valor;
    printf("Empilhado: %d\n", valor);
}
 
// Função para desempilhar (pop)
int desempilhar() {
    if (topo == -1) {
        printf("Erro: Pilha vazia!\n");
        return -1;   // valor de erro
    }
    int valor = pilha[topo];
    topo--;
    return valor;
}
 
// Função para consultar o topo (peek)
int consultar_topo() {
    if (topo == -1) {
        printf("Erro: Pilha vazia!\n");
        return -1;
    }
    return pilha[topo];
}
 
// Verifica se a pilha está vazia
int esta_vazia() {
    return topo == -1;
}
 
// Verifica se a pilha está cheia
int esta_cheia() {
    return topo == MAX - 1;
}
 
// Mostrar toda a pilha (do topo até a base)
void mostrar_pilha() {
    if (esta_vazia()) {
        printf("Pilha vazia!\n");
        return;
    }
    
    printf("Pilha (do topo para a base): ");
    for (int i = topo; i >= 0; i--) {
        printf("%d ", pilha[i]);
    }
    printf("\n");
}
 
int main() {
    empilhar(10);
    empilhar(20);
    empilhar(30);
    empilhar(40);
    
    mostrar_pilha();
    
    printf("Desempilhado: %d\n", desempilhar());
    printf("Desempilhado: %d\n", desempilhar());
    
    mostrar_pilha();
    
    printf("Topo atual: %d\n", consultar_topo());
    
    return 0;
}