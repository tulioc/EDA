#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;


struct lista {
  Lista *proximo;
  int valor;
};

// Declarando esqueleto das funções.

Lista* criaPrimeiroElemento(int valorRecebido);
Lista* insereValorListaOrdenada(Lista* lista, int valorRecebido);
Lista* retiraElemento(Lista* lista, int valorRecebido);
void imprimirLista(Lista* lista);
void liberaLista(Lista* lista);


// Função Main
int main (void) {

  Lista* lista;
  lista = criaPrimeiroElemento(8);
  lista = insereValorListaOrdenada(lista,5);
  lista = insereValorListaOrdenada(lista,2);
  lista = insereValorListaOrdenada(lista,1);
  lista = insereValorListaOrdenada(lista,4);
  lista = insereValorListaOrdenada(lista,20);
  lista = insereValorListaOrdenada(lista,12);
  imprimirLista(lista);
  lista = retiraElemento(lista,4);
  imprimirLista(lista);
  liberaLista(lista);
  return 0;
}


// Implementando Funções.

Lista* criaPrimeiroElemento(int valorRecebido) {
  Lista* lista;
  lista = (Lista*) malloc(sizeof(Lista)); // Alocando espaço na memória para o primeiro elemento.
  lista->valor = valorRecebido; // O valor do primeiro elemento será o valor recebido como parâmetro na função.
  lista->proximo = NULL; // O primeiro elemento irá apontar para NULL.
  return lista; // A função retorna o ponteiro para o primeiro elemento.
}

Lista* insereValorListaOrdenada(Lista* lista, int valorRecebido) {
  Lista* novoElemento;
  Lista* anterior = NULL;
  Lista* varredor = lista;

  while(varredor !=NULL && varredor->valor < valorRecebido) {
    anterior = varredor;
    varredor = varredor->proximo;
  }

  novoElemento = (Lista*) malloc(sizeof(Lista));
  novoElemento->valor = valorRecebido;

  if (anterior == NULL) {
    novoElemento->proximo = lista;
    lista = novoElemento;
  } else {
    novoElemento->proximo = anterior->proximo;
    anterior->proximo = novoElemento;
  }

  return lista;
}

Lista* retiraElemento(Lista* lista, int valorRecebido) {
  Lista* anterior = NULL; // Ponteiro para elemento anterior
  Lista* varredor = lista; // Ponteiro para percorrer a lista

  printf("O elemento escolhido para ser removido foi o %d\n", valorRecebido);

  while(varredor != NULL && varredor->valor !=valorRecebido) {
    anterior = varredor;
    varredor = varredor->proximo;
  }
  // Se o elemento não foi encontrado, retorno a lista original.
  if (varredor == NULL) {
    return lista;

  } else if (anterior == NULL) {
    /*Se o anterior continuar como NULL,
     significa que o elemento a ser excluído, era o primeiro elemento.*/
     /*Sendo assim, o ponteiro da lista, passa a apontar para o próximo valor da lista*/
    lista = varredor->proximo;
  }
  else {
    /* O ponteiro próximo do elemento anterior, receberá o ponteiro próximo do varredor*/
    anterior->proximo = varredor->proximo;
  }
  free(varredor);
  return lista;
}

void liberaLista(Lista* lista) {
  Lista* varredor = lista;
  while (varredor != NULL) {
    // Guarda referência p/ próximo elemento.
    Lista* referenciaProximo = varredor->proximo;
    free(varredor);
    varredor = referenciaProximo;
  }
}

void imprimirLista (Lista* lista) {
  Lista* varredor;
  for (varredor = lista; varredor!= NULL; varredor = varredor->proximo) {
    printf("Valor : %d\n", varredor->valor);
  }
}
