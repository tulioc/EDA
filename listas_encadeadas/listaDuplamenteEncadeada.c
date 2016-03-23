#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;

struct lista {
  int valor;
  struct lista* anterior;
  struct lista* proximo;
};

Lista* removerElemento(Lista* lista, int valorRecebido);
Lista* buscaElemento(Lista* lista, int valorRecebido);
Lista* criaPrimeiroElemento(int valorRecebido);
Lista* insereValorLista(Lista* lista, int valorRecebido);
void imprimirLista(Lista* lista);




int main (void) {

  Lista* lista;
  lista = criaPrimeiroElemento(20);
  lista = insereValorLista(lista,35);
  imprimirLista(lista);
  lista = removerElemento(lista,20);
  printf("\n");
  imprimirLista(lista);

  return 0;
}

Lista* buscaElemento(Lista* lista, int valorRecebido) {
  Lista* varredor;
  for (varredor = lista; varredor!=NULL; varredor = varredor->proximo) {
    if (varredor->valor == valorRecebido) {
      return varredor;
    }
  }
  return NULL;
}


Lista* removerElemento(Lista* lista, int valorRecebido) {

  Lista* varredor = buscaElemento(lista,valorRecebido);

  if(varredor==NULL) {
    return lista;
  }

  if(lista == varredor) {
    lista = varredor->proximo;
  } else {
    varredor->anterior->proximo = varredor->proximo;
  }

  if(varredor->proximo != NULL) {
    varredor->proximo->anterior = varredor->anterior;
  }

  free(varredor);
  return lista;
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
