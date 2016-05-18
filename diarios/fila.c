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
#define N 10;

typedef struct fila_vetor Fila_vetor;
typedef struct fila_lista Fila_lista;
typedef struct node Node;

struct fila_vetor {
  int pos_ini;
  int n_elementos;
  int vetor[N];
};

struct fila_lista {
  Node* ini;
  Node* fim;
};

struct node {
  Node* proximo;
  int valor;
};


Fila_vetor* cria_fila_vetor(void) {
  Fila_vetor* nova_fila = (Fila_vetor*)malloc(sizeof(Fila_vetor));
  nova_fila->pos_ini = 0;
  nova_fila->n_elementos = 0;
  
  return nova_fila;
}
