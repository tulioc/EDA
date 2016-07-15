#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct arvore Arvore;

struct arvore {
  int info;
  struct arvore* direita;
  struct arvore* esquerda;
};


Arvore* arvore_cria_elemento(int info) {
  Arvore* nova_arvore = (Arvore*)malloc(sizeof(Arvore));
  nova_arvore->info = info;
  nova_arvore->esquerda = NULL;
  nova_arvore->direita = NULL;
  return nova_arvore;
}

void adiciona(int info, Arvore* pai) {
  Arvore* novo_elemento = arvore_cria_elemento(info);

  if (novo_elemento->info == pai->info) {

  }

  if (novo_elemento->info > pai->info && pai->direita == NULL) {
      pai->direita = novo_elemento;
  } else if (novo_elemento->info > pai->info && pai->direita != NULL) {
    adiciona(info,pai->direita);
  }

  if(novo_elemento->info < pai->info && pai->esquerda == NULL){
    pai->esquerda = novo_elemento;
  } else if (novo_elemento->info < pai->info && pai->esquerda != NULL) {
    adiciona(info,pai->esquerda);
  }
}

int arv_vazia (Arvore* a) {
  return a==NULL;
}

int altura_arvore(Arvore* pai) {
  int direita = 0;
  int esquerda = 0;
  if (pai == NULL) {
    return 0;
  }
  direita = altura_arvore(pai->direita);
  esquerda = altura_arvore(pai->esquerda);
  if (esquerda > direita) {
    return esquerda+1;
  } else {
    return direita+1;
  }
}

int eficiencia(elementos,max) {
  float el;
  float maximo;
  float eficiencia = 0;
  int total = 0;
  el = elementos;
  maximo = max;
  eficiencia = el/maximo;
  total = eficiencia*100;
  return total;
}

int qtd_nos_recursivo(Arvore*pai) {
  int contador = 0;
  if (pai !=NULL) {
    contador = 1 + qtd_nos_recursivo(pai->esquerda) +  qtd_nos_recursivo(pai->direita);
  }
  return contador;
}

int main () {
  int vezes = 0;
  int contador = 1;
  int info = 0;
  int max = 0;
  int altura = 0;
  float ef = 0;
  scanf("%d", &vezes);
  scanf("%d",&info);
  Arvore* pai = arvore_cria_elemento(info);
  for(; contador < vezes; contador++) {
      scanf("%d",&info);
      adiciona(info,pai);
  }
  max = pow(2,altura_arvore(pai)) -1;
  printf("Eficiencia de uso: %d%%\n",eficiencia(qtd_nos_recursivo(pai),max));
}
