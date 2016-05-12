/*
1.
Implementar um programa para ler entradas do teclado e armazená-los numa fila, considerando as seguintes estruturas de dados
a) Vetor simples de 7 posições
b) Vetor circular de 7 posições
c) Lista encadeada simples
d) Lista Circular simplesmente encadeada

Entradas possíveis :
 I- Incluir elemento (int)
 R - Retirar elemento
 P - Imprimir fila
 F - Finalizar o loop de entrada de dados

 Exemplo : I22, I10, I14, 126, R,R,P,F


2.
Realizar os procedimentos do exercício 1
para o caso de pilhas. Nesse caso, implementar apenas
as seguintes estruturas
Vetor simples de 12 posições
Lista encadeada simples.


*/


#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
typedef struct gestor Gestor;

struct gestor {
  Node* inicio;
  Node* fim;
  int quantidade_nos;
  int qnt_max;
};

struct node {
  int valor;
  Node* proximo;
};

Gestor* cria_gestor (int qnt_max) {
  Gestor* gestor;
  gestor = (Gestor*) malloc(sizeof(Gestor));
  gestor->inicio = NULL;
  gestor->fim = NULL;
  gestor->qnt_max = qnt_max;
  return gestor;
}


Node* cria_lista(int valor) {
  Node* primeiro_elemento;
  primeiro_elemento = (Node*) malloc(sizeof(Node));
  primeiro_elemento->valor = valor;
  primeiro_elemento->proximo = NULL;
  return primeiro_elemento;
}

void add_elemento_ES(Gestor* gestor, int valor) {
  Node* novo_elemento = cria_lista(valor);
  if (gestor->quantidade_nos == 0) {
    gestor->inicio = novo_elemento;
    gestor->fim = novo_elemento;
    gestor->quantidade_nos++;
  } else if (gestor->quantidade_nos > 0 && gestor->quantidade_nos < gestor->qnt_max) {
    novo_elemento->proximo = gestor->inicio;
    gestor->inicio = novo_elemento;
    gestor->quantidade_nos++;
  } else {

  }
}

void add_elemento_CES(Gestor* gestor, int valor) {
  Node* novo_elemento = cria_lista(valor);
  if (gestor->quantidade_nos == 0) {
    gestor->inicio = novo_elemento;
    gestor->fim = novo_elemento;
    gestor->quantidade_nos++;
  } else if (gestor->quantidade_nos > 0 && gestor->quantidade_nos < gestor->qnt_max) {
    novo_elemento->proximo = gestor->inicio;
    gestor->fim->proximo = novo_elemento;
    gestor->inicio = novo_elemento;
    gestor->quantidade_nos++;
  } else {

  }
}

void remove_elemento_CES(Gestor* gestor) {
  Node* burn;
  burn = gestor->inicio;
  gestor->inicio = gestor->inicio->proximo;
  gestor->fim->proximo = gestor->inicio;
  free(burn);
}

void remove_elemento_ES(Gestor* gestor) {
  Node* burn;
  burn = gestor->inicio;
  gestor->inicio = gestor->inicio->proximo;
  free(burn);
}

int main (void) {

return 0;
}
