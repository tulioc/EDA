#include  <stdio.h>
#include <stdlib.h>

typedef struct node Node;
typedef struct fila Fila;

struct fila {
  int qnt_nos;
  Node* ini;
  Node* fim;
};

struct node {
  Node* proximo;
  float valor;
};


Fila* cria_fila(void) {
  Fila* nova_fila = (Fila*)malloc(sizeof(Fila));
  nova_fila->ini = nova_fila->fim = NULL;
  nova_fila->qnt_nos = 0;
  return nova_fila;
}

void fila_add(Fila* fila, float valor) {
  Node* novo_elemento = (Node*)malloc(sizeof(Node));
  novo_elemento->valor = valor;
  novo_elemento->proximo = NULL;
    if (fila->qnt_nos == 0) {
      fila->ini = novo_elemento;
      fila->fim = novo_elemento;
      fila->qnt_nos++;
  } else {
    fila->fim->proximo = novo_elemento;
    fila->fim = novo_elemento;
    fila->qnt_nos++;
  }
}

float fila_delete(Fila* fila) {
  if (fila->qnt_nos == 0) {
    printf("Fila vazia \n");
  } else {
    Node* alvo;
    alvo = fila->ini;
    fila->ini = fila->ini->proximo;
    return alvo->valor;
    free(alvo);
   }
}

void imprime_fila(Fila* fila) {
  Node* aux;
  aux = fila->ini;
  while(aux != fila->fim) {
    printf("%.2f\n", aux->valor);
    aux = aux->proximo;
  }
}


int main (void) {
  Fila* teste;
  teste = cria_fila();
  fila_add(teste, 1);
  fila_add(teste, 2);
  fila_add(teste, 3);
  fila_add(teste, 4);
  imprime_fila(teste);
  fila_delete(teste);
  imprime_fila(teste);

  return 0;
}
