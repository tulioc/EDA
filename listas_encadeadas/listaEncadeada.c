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
Lista* insereValorNaUltimaPos(Lista* lista, int valorRecebido);
Lista* removerElemento(Lista* lista, int valorRecebido);
Lista* buscaElemento(Lista* lista, int valorRecebido);
Lista* retiraElemento(Lista* lista, int valorRecebido);
Lista* retiraUltimoElemento(Lista* lista);
void liberaLista(Lista* lista);
void imprimirLista(Lista* lista);


int main (void) {

  Lista* lista;

  lista = criaListaNula();
  lista = insereValorLista(lista,10);
  lista = insereValorLista(lista,20);
  lista = insereValorLista(lista,30);
  lista = insereValorLista(lista,40);
  imprimirLista(lista);
  lista = retiraUltimoElemento(lista);
  printf("\n");
  imprimirLista(lista);

  return 0;
}

// Cria o primeiro elemento da lista, apontando pra null.
Lista* criaListaNula(void) {
  return NULL;
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

// Insere novo valor em uma dada lista.
Lista* insereValorLista(Lista* lista, int valorRecebido) {
  Lista* novo = (Lista*) malloc(sizeof(Lista)); // Alocando espaço para o elemento.
  novo->valor = valorRecebido;
  novo->proximo = lista;
  return novo;
}

// Função para buscar um elemento de uma dada lista.
Lista* buscaElemento(Lista* lista, int valorRecebido) {
  Lista* varredor; // Criando ponteiro para varrer a lista
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

Lista* insereValorNaUltimaPos(Lista* lista, int valorRecebido) {
  Lista* varredor;
  varredor = lista;
  while(varredor->proximo != NULL) {
    varredor = varredor->proximo;
  }
  Lista* novoElemento = (Lista*) malloc(sizeof(Lista));
  novoElemento->valor = valorRecebido;
  novoElemento->proximo = NULL;
  varredor->proximo = novoElemento;

  return lista;
}




// Função que retira um elemento de uma dada lista
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

Lista* retiraUltimoElemento(Lista* lista) {
  Lista* varredor1;
  Lista* varredor2;
  varredor1 = lista;
  varredor2 = lista->proximo;
  while(varredor2->proximo != NULL) {
    varredor2 = varredor2->proximo;
    varredor1 = varredor1->proximo;
  }
  free(varredor2);
  varredor1->proximo = NULL;
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
