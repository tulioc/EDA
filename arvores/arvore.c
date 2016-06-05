#include <stdio.h>
#include <stdlib.h>
#define ELEMENTOS 10
typedef struct arvore Arvore;
typedef struct fila Fila;
typedef struct node Node;

struct arvore {
  char info;
  struct arvore* esquerda;
  struct arvore* direita;
};

struct fila {
  Node* inicio;
  Node* atual;
  Node* fim;
  int n_elementos;
};

struct node {
  char valor;
  Node* proximo;
};

Fila* cria_fila(void) {
  Fila* nova_fila = (Fila*)malloc(sizeof(Fila));
  nova_fila->inicio = NULL;
  nova_fila->fim = NULL;
  nova_fila->n_elementos = 0;
  return nova_fila;
}

void fila_add(Fila* fila, char valor) {
  Node* novo_elemento = (Node*)malloc(sizeof(Node));
  novo_elemento->valor = valor;
  novo_elemento->proximo = NULL;
  if (fila->n_elementos == 0) {
    fila->inicio = novo_elemento;
    fila->fim = novo_elemento->proximo;
    fila->atual = novo_elemento;
    fila->n_elementos++;
  } else {
    fila->atual->proximo = novo_elemento;
    fila->atual = novo_elemento;
    fila->fim = novo_elemento;
    fila->fim = fila->fim->proximo;
    fila->n_elementos++;
  }
}

Arvore* arvore_cria_vazia(void) {
  return NULL;
}

Arvore* arvore_cria(char info, Arvore* esquerda, Arvore* direita) {

  Arvore* nova_arvore = (Arvore*)malloc(sizeof(Arvore));
  nova_arvore->info = info;
  nova_arvore->esquerda = esquerda;
  nova_arvore->direita = direita;
  return nova_arvore;

}

int arvore_pertence(Arvore* alvo, char info) {
  if (alvo == NULL) {
    return 0;
  } else {
    return alvo->info == info ||
    arvore_pertence(alvo->esquerda, info) ||
    arvore_pertence(alvo->direita, info);
  }
}


int arv_vazia (Arvore* a) {
  return a==NULL;
}


void imprime_arvore_prefixa(Arvore* alvo) {

  if (!arv_vazia(alvo)) {
    printf("%c\n", alvo->info);
    imprime_arvore_prefixa(alvo->esquerda);
    imprime_arvore_prefixa(alvo->direita);
  }
}

void imprime_arvore_infixa(Arvore* alvo) {
  if (!arv_vazia(alvo)) {
    imprime_arvore_infixa(alvo->esquerda);
    printf("%c\n", alvo->info);
    imprime_arvore_infixa(alvo->direita);
  }
}

void imprime_arvore_posfixa(Arvore* alvo) {
  if (!arv_vazia(alvo)) {
    imprime_arvore_posfixa(alvo->direita);
    imprime_arvore_posfixa(alvo->esquerda);
    printf("%c\n", alvo->info);
  }
}

void imprime_arvore_largura(Arvore* alvo) {
  Fila* fila;
  fila = cria_fila(void);
  fila_add(fila,alvo->info);
  Node* aux = fila->inicio;
  fila_add(fila, alvo->esquerda->info);




}


int main (void) {

Arvore* d = arvore_cria('d', arvore_cria_vazia(), arvore_cria_vazia());
Arvore* b = arvore_cria('b',arvore_cria_vazia(),d);
Arvore* e = arvore_cria('e', arvore_cria_vazia(), arvore_cria_vazia());
Arvore* f = arvore_cria('f', arvore_cria_vazia(), arvore_cria_vazia());
Arvore* c = arvore_cria('c',e,f);
Arvore* a = arvore_cria('a',b,c);

  printf("\n PRE FIXA\n");
  imprime_arvore_prefixa(a);
  printf("\n POS FIXA\n");
  imprime_arvore_posfixa(a);
  printf("\n INFIXA \n");
  imprime_arvore_infixa(a);
return 0;
}
