#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;

struct lista {
  int valor;
  struct lista* anterior;
  struct lista* proximo;
};

Lista* criaPrimeiroElemento(int valorRecebido);
Lista* insereValorLista(Lista* lista, int valorRecebido);
void imprimirLista(Lista* lista);



int main (void) {

  Lista* lista;
  lista = criaPrimeiroElemento(20);
  lista = insereValorLista(lista,35);
  imprimirLista(lista);

  return 0;
}

Lista* insereValorLista(Lista* lista, int valorRecebido) {
  Lista* novoElemento;
  novoElemento = (Lista*) malloc(sizeof(Lista));
  novoElemento->valor = valorRecebido;
  novoElemento->proximo = lista;
  novoElemento->anterior = NULL;
  if (lista != NULL) {
    lista->anterior = novoElemento;
  }
  return novoElemento;
}

Lista* criaPrimeiroElemento(int valorRecebido) {
  Lista* lista;
  lista = (Lista*) malloc(sizeof(Lista));
  lista->valor = valorRecebido;
  lista->anterior = NULL;
  lista->proximo = NULL;
  return lista;
}

void imprimirLista (Lista* lista) {
  Lista* varredor;
  for (varredor = lista; varredor!= NULL; varredor = varredor->proximo) {
    printf("Valor : %d\n", varredor->valor);
  }
}
