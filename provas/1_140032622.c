#include <stdlib.h>
#include <stdio.h>

typedef struct node Node;
typedef struct gestor Gestor;

struct node {
int id;
Node* proximo;
Node* anterior;
};

struct gestor {
  int quantidade_nos;
  int quantidade_max;
  Node* inicio;
  Node* fim;
};

Gestor* criaGestor(int quantidade_max);
Node* criaNo(int valor_id);
Node* buscaID(Gestor* gestor, int alvo);
void insereProcesso(Gestor* gestor, int valor_id);
void removeID(Gestor* gestor, int alvo);
void imprimeLista(Gestor *lista);

int main (void) {

  return 0;
}


Gestor* criaGestor(int quantidade_max) {
  Gestor* novo_gestor = (Gestor*)malloc(sizeof(Gestor));
  novo_gestor->quantidade_nos = 0;
  novo_gestor->quantidade_max = quantidade_max;
  novo_gestor->inicio = NULL;
  novo_gestor->fim = NULL;
  return novo_gestor;
}

Node* criaNo(int valor_id) {
  Node* primeiro_elemento = (Node*)malloc(sizeof(Node));
  primeiro_elemento->id = valor_id;
  primeiro_elemento->proximo = NULL;
  primeiro_elemento->anterior = NULL;

  return primeiro_elemento;
}

void insereProcesso(Gestor* gestor, int valor_id) {

  Node* novo_elemento = criaNo(valor_id);

  if (gestor->quantidade_nos == 0) {
    gestor->inicio = novo_elemento;
    gestor->fim = novo_elemento;
    gestor->quantidade_nos++;

  } else if (gestor->quantidade_nos > 0 && gestor->quantidade_nos <= gestor->quantidade_max) {
    novo_elemento->anterior = gestor->fim;
    gestor->fim->proximo = novo_elemento;
    gestor->fim = novo_elemento;
    gestor->quantidade_nos++;

  } else {
    printf("Limite atingido \n");
  }
}

Node* buscaID(Gestor* gestor, int alvo) {
  Node* no_alvo = gestor->inicio;

  while(no_alvo->id != alvo && no_alvo->proximo != NULL) {
    no_alvo = no_alvo->proximo;
  }

  if(no_alvo->id == alvo) {
    return no_alvo;
  } else {
    return NULL;
  }
}

void removeID(Gestor* gestor, int alvo) {

  Node* no_alvo = buscaID(gestor, alvo);

  if(no_alvo != NULL) {
    if(no_alvo == gestor->fim) {
      gestor->fim = no_alvo->anterior;
      gestor->fim->proximo = NULL;
      gestor->quantidade_nos--;
      free(no_alvo);

    } else {
      int salvaID = gestor->fim->id;
      gestor->fim->id = no_alvo->id;
      no_alvo->id = salvaID;
      gestor->fim = no_alvo;
      gestor->fim->proximo = NULL;
      gestor->quantidade_nos--;
      free(no_alvo->proximo);
    }
  } else {
    printf("ID não encontrado\n");
  }
}

void imprimeLista(Gestor* gestor) {
  int contador = 0;
  Node* auxiliar = gestor->inicio;
  for(; contador < gestor->quantidade_nos; contador++) {
    printf("%d", auxiliar->id);
    auxiliar = auxiliar->proximo;
  }
}
