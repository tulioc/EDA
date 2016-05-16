#include <stdio.h>
#include <stdlib.h>

typedef struct pilha Pilha;
typedef struct node Node;

struct node {
  float valor;
  struct node* proximo;
};

struct pilha {
  Node* topo;
};

Pilha* pilha_cria(void) {
  Pilha* nova_pilha = (Pilha*)malloc(sizeof(Pilha));
  nova_pilha->topo = NULL;
  return nova_pilha;
}

void pilha_push (Pilha* pilha, float valor) {
  Node* novo_elemento = (Node*)malloc(sizeof(Node));
  novo_elemento->valor = valor;
  novo_elemento->proximo = pilha->topo;
  pilha->topo = novo_elemento;
}

float pilha_pop (Pilha* pilha) {
  Node* topo;
  float v;
  if (pilha->topo == NULL) {
    printf("Pilha vazia\n");
    exit(1);
  } else {
    topo = pilha->topo;
    v = topo->valor;
    pilha->topo = topo->proximo;
    free(topo);
    return v;
  }
}

void pilha_libera (Pilha* pilha) {
  Node* varredor = pilha->topo;
  while(varredor != NULL) {
    Node* topo = varredor->proximo;
    free(varredor);
    varredor = topo;
  }
  free(pilha);
}

void imprime_pilha(Pilha* pilha) {

  if (pilha->topo == NULL) {
    printf("Pilha vazia \n");
    printf("\n====== FIM PILHA ======\n");
  } else {
    Node* aux;
    aux = pilha->topo;
    printf("\n====== INICIO PILHA ======\n");
    while(aux != NULL) {
      printf("%f\n", aux->valor);
      aux = aux->proximo;
    }
    printf("\n====== FIM PILHA ======\n");
  }
}





int main (void) {
  Pilha* teste;
  teste = pilha_cria();
  imprime_pilha(teste);
  pilha_push(teste, 6.2);
  imprime_pilha(teste);
  pilha_push(teste, 5.6);
  imprime_pilha(teste);
  pilha_push(teste, 7.6);
  imprime_pilha(teste);
  pilha_pop(teste);
  imprime_pilha(teste);

  return 0;
}
