#include <stdio.h>
#include <stdlib.h>


typedef struct arvore Arvore;

struct arvore {
  int info;
  struct arvore* direita;
  struct arvore* esquerda;
};

Arvore* cria_elemento (int info) {
  Arvore* novo_elemento = (Arvore*)malloc(sizeof(Arvore));
  novo_elemento->info = info;
  novo_elemento->direita = NULL;
  novo_elemento->esquerda = NULL;
  return novo_elemento;
}

void adiciona(int info, Arvore*pai) {
  Arvore* novo_elemento = cria_elemento(info);
  if (novo_elemento->info == pai->info) {

  }

  if (novo_elemento->info > pai->info && pai->direita == NULL) {
    pai->direita = novo_elemento;
  } else if (novo_elemento->info > pai->info && pai->direita != NULL) {
    adiciona(info,pai->direita);
  }

  if (novo_elemento->info < pai->info && pai->esquerda == NULL) {
      pai->esquerda = novo_elemento;
  } else if (novo_elemento->info < pai->info && pai->esquerda != NULL) {
    adiciona(info, pai->esquerda);
  }
}

int quantidade_pais(Arvore* pai) {
  int pais = 0;
  if (pai == NULL) {
    return 0;
  }
  if (pai->direita != NULL || pai->esquerda != NULL) {
    pais = 1 + quantidade_pais(pai->direita) + quantidade_pais(pai->esquerda);
  } else {
    return 0;
  }
    return pais;
}

int quantidade_folhas(Arvore*pai) {
  int folhas = 0;
  if (pai == NULL) {
    return 0;
  }
  if (pai->direita == NULL && pai->esquerda == NULL) {
    return 1;
  } else {
    return quantidade_folhas(pai->esquerda) + quantidade_folhas(pai->direita);
  }
}


int main (void) {
  int elementos = 0;
  int contador = 1;
  int info = 0;
  scanf("%d",&elementos);
  scanf("%d",&info);
  Arvore* pai = cria_elemento(info);
  for(; contador < elementos; contador++) {
    scanf("%d",&info);
    adiciona(info, pai);
  }

  printf("Raiz, %d folha(s) e %d pai(s).\n",quantidade_folhas(pai), quantidade_pais(pai));

  return 0;
}
