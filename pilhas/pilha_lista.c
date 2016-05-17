#include <stdio.h>
#include <stdlib.h>

typedef struct pilha Pilha;
typedef struct node Node;


struct pilha {
  Node* topo;
};

struct node {
  Node* proximo;
  float valor;
};


Pilha* cria_pilha(void) {
  Pilha* nova_fila = (Pilha*)malloc(sizeof(Pilha));
  nova_fila->topo = NULL;
  return nova_fila;
}

void pilha_add(Pilha* pilha, float valor) {
  Node* novo_elemento = (Node*)malloc(sizeof(Node));
  novo_elemento->valor = valor;
  novo_elemento->proximo = pilha->topo;
  pilha->topo = novo_elemento;
}

float pilha_delete(Pilha* pilha) {

  if (pilha->topo == 0) {
    printf("Pilha vazia\n");
  } else {
    Node* alvo;
    alvo = pilha->topo;
    pilha->topo = pilha->topo->proximo;
    return alvo->valor;
    free(alvo);
  }
}

void imprime_pilha(Pilha* pilha) {
  Node* aux;
  aux = pilha->topo;
  while(aux != NULL) {
    printf("%.2f\n", aux->valor);
    aux = aux->proximo;
  }
}

int main (void) {


      Pilha* teste;
      teste = cria_pilha();
      pilha_add(teste,1);
      pilha_add(teste,2);
      pilha_add(teste,3);
      imprime_pilha(teste);
      pilha_delete(teste);
      imprime_pilha(teste);


  return 0;
}
