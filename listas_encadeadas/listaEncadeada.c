#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
void adiciona_elemento_fim(Lista* lista, int info);
void deleta_elemento_fim(Lista* lista, int info);
void imprime_lista(Lista* lista);


int main (void) {
  Lista* lista = cria_lista();
  adiciona_elemento_fim(lista,10);
  adiciona_elemento_fim(lista,11);
  adiciona_elemento_fim(lista,12);
  deleta_elemento_fim(lista,12);
  imprime_lista(lista);
  return 0;
}

Lista* cria_lista(void) {
  printf("Criando Lista Vazia\n");
  sleep(1);
  Lista* nova_lista = (Lista*)malloc(sizeof(Lista));
  nova_lista->quantidade_elementos = 0;
  nova_lista->inicio = NULL;
  nova_lista->fim = NULL;
  return nova_lista;
  printf("Lista criada com sucesso\n");
}

No* cria_no(int info) {
  No* novo_no = (No*)malloc(sizeof(No));
  novo_no->info = info;
  novo_no->proximo = NULL;
  return novo_no;
}

No* busca_elemento(Lista* lista, int info) {
  No* alvo;
  alvo = lista->inicio;
  while(alvo->info != info) {
    alvo = alvo->proximo;
  }
  return alvo;
}

void adiciona_elemento_fim(Lista* lista, int info) {
  sleep(1);
  printf("Adicionando elemento %i ao final da lista\n", info);
  No* novo_elemento = cria_no(info);
  if(lista->quantidade_elementos == 0) {
    lista->inicio = novo_elemento;
    lista->fim = novo_elemento;
    lista->quantidade_elementos++;
  } else {
    lista->fim->proximo = novo_elemento;
    lista->fim = novo_elemento;
    lista->quantidade_elementos++;
  }
  sleep(1);
  printf("Elemento adicionado com sucesso!\n");
}

void deleta_elemento_fim(Lista* lista, int info) {
  sleep(1);
  printf("Removendo elemento %i da lista\n", info);
  if(lista->quantidade_elementos > 0) {
    No* aux = lista->inicio;
    while(aux->proximo != lista->fim) {
      aux = aux->proximo;
    }
    aux->proximo = NULL;
    free(lista->fim);
    lista->fim = aux;
    sleep(1);
    printf("Elemento removido com sucesso!\n");
  } else {
    printf("Lista sem elemento\n");
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
