/*
Uma lista encadeada, nada mais é, que uma struct com pelo menos duas estruturas:
Uma dada informação e um ponteiro que aponta para o próximo elemento da lista. Cada posição de uma lista encadeada é chamada de nó.

Funções de remover o elemento e reorganizar...
* Atualiza o valor da lista, se o elemento removido for o primeiro
* Caso contrário, apenas remove o elemento da lista.

*/

#include <stdio.h>
#include  <stdlib.h>

typedef struct lista Lista;

// Cria a estrutura da lista
struct lista {
  int valor;
  Lista *proximo;
};

// Declarando o 'esqueleto das funções'

Lista* criaListaNula(void);
Lista* insereValorLista(Lista* lista, int valorRecebido);
Lista* removerElemento(Lista* lista, int valorRecebido);
Lista* buscaElemento(Lista* lista, int valorRecebido);
void imprimirLista(Lista* lista);


int main (void) {

  Lista* lista;

  lista = criaListaNula();
  lista = insereValorLista(lista,10);
  lista = insereValorLista(lista,20);
  lista = insereValorLista(lista,30);
  lista = insereValorLista(lista,40);
  lista = buscaElemento(lista,40);
  imprimirLista(lista);

  return 0;
}


// Cria o primeiro elemento da lista, apontando pra null.
Lista* criaListaNula(void) {
  return NULL;
}

// Insere novo valor em uma dada lista.
Lista* insereValorLista(Lista* lista, int valorRecebido) {
  Lista* novo = (Lista*) malloc(sizeof(Lista));
  novo->valor = valorRecebido;
  novo->proximo = lista;
  return novo;
}

// Função para buscar um elemento de uma dada lista.
Lista* buscaElemento(Lista* lista, int valorRecebido) {
  Lista* varredor;
  for(varredor = lista; varredor!=NULL; varredor = varredor->proximo) {
      if(varredor->valor == valorRecebido) {
        printf("Valor recebido para busca : %d\n", valorRecebido);
        printf("Valor encontrado : %d\n", varredor->valor);
        return varredor;
      }
      else {
        printf("Elemento não foi encontrado na lista");
        return NULL;
      }
  }
  return lista;
}





void imprimirLista(Lista *lista) {

  /* Função recursiva que imprime Lista.
    if(lista != NULL) {
    printf("%d \n", lista->valor);
    imprimirLista(lista->proximo);
    }
    */

  Lista* varredor;
  for (varredor = lista; varredor!= NULL; varredor = varredor->proximo) {
    printf("Valor : %d\n", varredor->valor);
  }
}
