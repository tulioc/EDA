#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;

struct lista {
int valor;
Lista* proximo;
};

Lista* criaLista(int valorRecebido);
Lista* insereElemento(Lista* lista, int valorRecebido);
Lista* deletaElementoRec(Lista* lista, int valorRecebido);
void imprimeLista(Lista* lista);


int main (void) {

  Lista* exemplo;
  exemplo = criaLista(70);
  exemplo = insereElemento(exemplo,15);
  exemplo = insereElemento(exemplo,20);
  imprimeLista(exemplo);
  printf("\n");
  exemplo = deletaElementoRec(exemplo,15);
  imprimeLista(exemplo);


  return 0;
}

Lista* criaLista(int valorRecebido) {
  Lista* primeiroElemento;
  primeiroElemento = (Lista*) malloc(sizeof(Lista));
  primeiroElemento->valor = valorRecebido;
  primeiroElemento->proximo = NULL;
  return primeiroElemento;
}

Lista* insereElemento(Lista* lista, int valorRecebido) {
  Lista* novoElemento;
  novoElemento = (Lista*) malloc(sizeof(Lista));
  novoElemento->valor = valorRecebido;
  novoElemento->proximo = lista;
  return novoElemento;
}

Lista* deletaElementoRec(Lista* lista, int valorRecebido) {
  if (lista != NULL) {

    if(lista->valor == valorRecebido) {
      Lista* aux = lista;
      lista = lista->proximo;
      free(aux);
    }
    else {
      lista->proximo = deletaElementoRec(lista->proximo, valorRecebido);
    }
  }
  return lista;
}

void imprimeLista (Lista* lista) {
  if(lista != NULL) {
  printf("%d \n", lista->valor);
  imprimeLista(lista->proximo);
  }
}
