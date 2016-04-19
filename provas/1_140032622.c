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

  int contador = 0;
  int quantidade_max = 0;
  int numero_processos = 0;
  int id = 0;
  int registros_adicionais = 0;


  scanf("%d",&quantidade_max);
  //printf("Quantidade maxima : %d\n", quantidade_max);
  scanf("%d",&numero_processos);
// printf("Quantidade de processos : %d\n", numero_processos);

  Gestor* gestor = criaGestor(quantidade_max);
  for(; contador < numero_processos; contador++) {
    scanf("%d",&id);
    //printf("ID a ser adicionado : %d\n", id);
    insereProcesso(gestor,id);
  }

  contador = 0;
  id = 0;

  scanf("%d",&registros_adicionais);
  //printf("R : %d\n", registros_adicionais);
  char tipo_registro;

  for(; contador < registros_adicionais; contador++) {
    scanf("%d",&id);
    //printf("ID a ser adicionado : %d\n", id);
    scanf(" %c",&tipo_registro);
    //printf("Tipo de registro  : %c\n",tipo_registro);
    if (tipo_registro == 't') {
      if(gestor->quantidade_nos > 0) {
          removeID(gestor,id);
      }
    }
    else if (tipo_registro == 'n') {
      if(gestor->quantidade_nos < quantidade_max) {
          insereProcesso(gestor,id);
      }

    } else {
      // NADA
    }
  }

  imprimeLista(gestor);

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

  } else if (gestor->quantidade_nos > 0 && gestor->quantidade_nos < gestor->quantidade_max) {
    novo_elemento->anterior = gestor->fim;
    gestor->fim->proximo = novo_elemento;
    gestor->fim = novo_elemento;
    gestor->quantidade_nos++;

  } else {

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



  if (gestor->quantidade_nos > 0) {
    Node* no_alvo = buscaID(gestor, alvo);
    if(no_alvo != NULL) {
      if(no_alvo == gestor->fim) {
        gestor->fim = no_alvo->anterior;
        gestor->fim->proximo = NULL;
        gestor->quantidade_nos--;
        free(no_alvo);

      } else {
        Node* kill;
        int salvaID = gestor->fim->id;
        gestor->fim->id = no_alvo->id;
        no_alvo->id = salvaID;
        kill = gestor->fim;
        gestor->fim = gestor->fim->anterior;
        gestor->fim->proximo = NULL;
        gestor->quantidade_nos--;
        free(kill);
      }
    } else {
      printf("ID não encontrado\n");
    }
  } else {

  }
}

void imprimeLista(Gestor* gestor) {
  int contador = 0;
  Node* auxiliar = gestor->inicio;
  if (gestor->quantidade_nos == 0) {
      printf("V = []\n");
  } else {
    printf("V = [");
    for (; contador < gestor->quantidade_nos; contador++) {

      if (contador == (gestor->quantidade_nos - 1)) {
        printf("%d", auxiliar->id);
      } else {
        printf("%d, ", auxiliar->id);
      }
      auxiliar = auxiliar->proximo;
    }
    printf("]\n");
  }
}
