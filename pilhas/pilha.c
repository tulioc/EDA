#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;


struct lista {
  Lista *proximo;
  float valor;
};

struct pilha {
  Lista* topo;
};


Pilha* criaPilha(void);
void pushPilha(Pilha* pilha, float valorRecebido);
float popPilha(Pilha* pilha);

int main (void) {


  return 0;
}



Pilha* criaPilha(void) {
  Pilha* primeiroElemento;
  primeiroElemento = (Pilha*)malloc(sizeof(Pilha));
  primeiroElemento->topo = NULL;
  return primeiroElemento;
}

void pushPilha(Pilha* pilha, float valorRecebido) {
  Lista* novoElemento = (Lista*)malloc(sizeof(Lista));
  novoElemento->valor = valorRecebido;
  novoElemento->proximo = pilha->topo;
  pilha->topo = novoElemento;

}

float popPilha(Pilha* pilha) {
  Lista* aux;
  float valor;
  aux = pilha->topo;
  valor = aux->valor;
  pilha->topo = aux->proximo;
  free(t);
  return valor;

}
