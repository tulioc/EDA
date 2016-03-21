/*
Uma lista encadeada, nada mais é, que uma struct com pelo menos duas estruturas:
Uma dada informação e um ponteiro que aponta para o próximo elemento da lista. Cada posição de uma lista encadeada é chamada de nó.


Tipos de listas :

 - Lista circular
 Lista que o último elemento aponta para o primeiro elemento, e não para NIL.
 - lista duplamente encadeada
 Lista com apontadores para o próximo elemento, e também para o elemento anterior.
 - Lista circular duplamente encadeada
 - Lista heterogênea
 Lista com elementos heterogêneos.

 EX:

typedef struct elemento Elemento;

 strcuct elemento {
 int info;
 struct elemento* prox;
};

Elemento* lst_cria (void) {
return NULL;
}

Elemento* lst_insere (Elemento* 1st, int val) {

  Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
  novo->info = val;
  novo->prox = 1st;
  return novo;
}


Funções de remover o elemento e reorganizar...
* Atualiza o valor da lista, se o elemento removido for o primeiro
* Caso contrário, apenas remove o elemento da lista.

*/

#include <stdio.h>
#include  <stdlib.h>

typedef struct elemento Elemento;

struct elemento {
  int valor;
  Elemento *proximo;
};

Elemento* criaListaNula (void) {
return NULL;
}


Elemento* insereValorLista (Elemento* lista, int valorRecebido) {

  Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
  novo->valor = valorRecebido;
  novo->proximo = lista;

  return novo;
}


void removerElemento (Elemento *tmp, int valor) {


}

void imprimirLista (Elemento *tmp) {

  if(tmp != NULL)
{
  printf("%d \n", tmp->valor);
  imprimirLista(tmp->proximo);
}


}

int main (void) {

  Elemento* lista;

  lista = criaListaNula();
  lista = insereValorLista(lista,10);
  lista = insereValorLista(lista,20);
  lista = insereValorLista(lista,30);
  lista = insereValorLista(lista,40);
  imprimirLista(lista);


  return 0;
}
