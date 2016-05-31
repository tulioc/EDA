#include <stdio.h>
#include <stdlib.h>

typedef struct arvore Arvore;







struct arvore {
  char info;
  struct arvore* esquerda;
  struct arvore* direita;
};

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
