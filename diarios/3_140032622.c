#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
typedef struct gestor Gestor;

struct aluno {
  char *matricula;
  char *nome;
  int p1,p2,p3;
  float media;
  char result[3];
};


struct node {
  int valor;
  Node* proximo;
  Node* anterior;
};

struct gestor {

  int quantidade_nos;
  int quantidade_max;

  Node* inicio;
  Node* fim;
};


Gestor* cria_gestor(int quantidade_max) {
  Gestor* novo_gestor = (Gestor*)malloc(sizeof(Gestor));
  novo_gestor->quantidade_max = quantidade_max;
  novo_gestor->quantidade_nos = 0;
  novo_gestor->inicio = NULL;
  novo_gestor->fim = NULL;
  return novo_gestor;
}

Node* cria_node(int valor) {
  Node* novo_node = (Node*)malloc(sizeof(Node));
  novo_node->proximo = NULL;
  novo_node->anterior = NULL;
  novo_node->valor = valor;
  return novo_node;
}

void adiciona_elemento(Gestor* gestor, int valor) {
  Node* novo_elemento = cria_node(valor);
  if (gestor->quantidade_nos == 0) {
    gestor->inicio = novo_elemento;
    gestor->fim = novo_elemento;
    gestor->quantidade_nos++;
  } else if (gestor->quantidade_nos < gestor->quantidade_max && gestor->quantidade_nos > 0) {
    gestor->inicio->anterior = novo_elemento;
    novo_elemento->proximo = gestor->inicio;
    gestor->inicio = novo_elemento;
    novo_elemento->anterior = gestor->fim;
    gestor->fim->proximo = gestor->inicio;
    gestor->quantidade_nos++;

  } else {
    //NADA
  }
}

Node* busca_no (Gestor* gestor, int alvo) {
  Node* no_alvo = gestor->inicio;

  while(no_alvo->valor != alvo) {
    no_alvo = no_alvo->proximo;
  }

  if(no_alvo->valor == alvo) {
    return no_alvo;
  } else {
    return NULL;
  }
}

void remove_no (Gestor* gestor, int alvo) {
  Node* no_alvo = busca_no(gestor, alvo);
  Node* auxA = no_alvo->anterior;
  Node* auxP = no_alvo->proximo;
  if (no_alvo == gestor->inicio) {
    gestor->fim->proximo = gestor->inicio->proximo;
    gestor->inicio = gestor->inicio->proximo;
    gestor->inicio->anterior = gestor->fim;
    free(no_alvo);
    gestor->quantidade_nos--;
  } else if (no_alvo == gestor->fim) {
    gestor->fim = gestor->fim->anterior;
    gestor->fim->proximo = gestor->inicio;
    gestor->inicio->anterior = gestor->fim;
    free(no_alvo);
    gestor->quantidade_nos--;
  } else {
    auxA->proximo = auxP;
    auxP->anterior = auxA;
    free(no_alvo);
    gestor->quantidade_nos;
  }
}


void imprime_lista (Gestor* gestor) {
  Node* aux = gestor->inicio;
  Node* auxU = gestor->fim;
  while (aux != auxU) {
    printf("%d\n",aux->valor);
    aux = aux->proximo;
  }
  printf("%d\n",aux->valor);
}

int main (void) {

Gestor* gestor;
gestor = cria_gestor(10);
int contador = 0;
for (contador = 0; contador < 10; contador++) {
  adiciona_elemento(gestor,contador);
}

imprime_lista(gestor);
remove_no(gestor,5);
printf("\n");
imprime_lista(gestor);


  return 0;
}
