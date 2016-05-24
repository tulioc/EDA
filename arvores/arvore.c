#include <stdio.h>
#include <stdlib.h>

typedef struct arvore Arvore;

struct arvore {
  int info;
  struct arvore* esquerda;
  struct arvore* direita;
};

Arvore* arvore_cria_vazia(void) {
  return NULL;
}

Arvore* arvore_cria(int info, Arvore* esquerda, Arvore* direita) {

  Arvore* nova_arvore = (Arvore*)malloc(sizeof(Arvore));
  nova_arvore->info = info;
  nova_arvore->esquerda = esquerda;
  nova_arvore->direita = direita;
  return nova_arvore;

}

int arvore_pertence(Arvore* alvo, int info) {
  if (alvo == NULL) {
    return 0;
  } else {
    return alvo->info == info ||
    arvore_pertence(alvo->esquerda, info) ||
    arvore_pertence(alvo->direita, info);
  }
}

void imprime_arvore(Arvore* alvo) {
  if (alvo == NULL) {

  } else  {
    printf("%d", alvo->info);
    imprime_arvore(alvo->esquerda);
    imprime_arvore(alvo->direita);
  }
}


int main (void) {


return 0;
}
