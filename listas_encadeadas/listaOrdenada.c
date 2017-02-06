#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;
typedef struct no No;

struct no {
  int info;
  No* proximo;
};

struct lista {
  int quantidade_elementos;
  No* inicio;
  No* fim;
};

Lista* cria_lista(void);
No* cria_no(int info);
No* busca_elemento(Lista* lista, int info);
void adiciona_elemento(Lista* lista, int info);
void deleta_elemento(Lista* lista, int info);
void imprime_lista(Lista* lista);
void libera_lista(Lista* lista);

int main (void) {
  Lista* lista = cria_lista();
  adiciona_elemento(lista,20);
  adiciona_elemento(lista,18);
  adiciona_elemento(lista,16);
  adiciona_elemento(lista,22);
  adiciona_elemento(lista,5);
  adiciona_elemento(lista,17);
  adiciona_elemento(lista,15);
  imprime_lista(lista);
  libera_lista(lista);
}

Lista* cria_lista(void) {
  Lista* nova_lista = (Lista*)malloc(sizeof(Lista));
  nova_lista->quantidade_elementos = 0;
  nova_lista->inicio = NULL;
  nova_lista->fim = NULL;
  return nova_lista;
}

No* cria_no(int info) {
  No* novo_no = (No*)malloc(sizeof(No));
  novo_no->info = info;
  novo_no->proximo = NULL;
  return novo_no;
}

void adiciona_elemento(Lista* lista, int info) {
  No* novo_elemento = cria_no(info);
  if(lista->quantidade_elementos == 0) {
    lista->inicio = novo_elemento;
    lista->fim = novo_elemento;
    lista->quantidade_elementos++;
  } else {
    No* anterior = NULL;
    No* varredor = lista->inicio;
    while(varredor != NULL && varredor->info < info) {
      anterior = varredor;
      varredor = varredor->proximo;
    }

    No* novo_elemento = cria_no(info);
    novo_elemento->info = info;


    if(anterior == NULL) {
      novo_elemento->proximo = lista->inicio;
      lista->inicio = novo_elemento;
    } else {
      novo_elemento->proximo = anterior->proximo;
      anterior->proximo = novo_elemento;
    }
  }
}

void imprime_lista(Lista* lista) {
  sleep(1);
  printf("Imprimindo lista...\n");
  sleep(1);
  No* aux;
  aux = lista->inicio;
  while(aux != NULL) {
    printf("%d\n",aux->info);
    aux = aux->proximo;
  }
}

void libera_lista(Lista* lista) {
  No* aux;
  aux = lista->inicio;
  while(aux != NULL) {
    No* proximo = aux->proximo;
    free(aux);
    aux = proximo;
  }
}
