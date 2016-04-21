/*
fwcruz@unb.br

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node Node;
typedef struct gestor Gestor;
typedef struct aluno Aluno;

struct aluno {
  char nome[30];
  int matricula;
  int p1,p2,p3;
  int media;
};


struct node {
  int valor;
  Aluno* aluno;
  Node* proximo;
  Node* anterior;
};

struct gestor {
  int quantidade_nos;
  int quantidade_max;
  Node* inicio;
  Node* fim;
};


Gestor* cria_gestor(int quantidade_max);
Node* cria_node(int valor);
/*Node* busca_no(Gestor* gestor, int alvo);*/
void calcula_matricula(Aluno* aluno,int valor);
void adiciona_elemento(Gestor* gestor, int valor);
/*void remove_no(Gestor* gestor, int alvo);*/
void leia_string(char* palavra);
void imprime_lista(Gestor* gestor, Node* varredor);


int main (void) {
  Gestor* gestor;
  Node* varredor;
  char enter;
  int num_alunos = 0;
  int contador = 0;
  printf("Digite o número de alunos da turma : \n");
  scanf("%d",&num_alunos);
  scanf("%c",&enter);
  gestor = cria_gestor(num_alunos);
  for (; contador < num_alunos; contador++) {
    adiciona_elemento(gestor,contador);
  }

  varredor = gestor->fim;
  printf("\n");
  printf("MATRÍCULA           ALUNO                    MÉDIA");
  printf("\n------------------------------------------------------ \n");
  imprime_lista(gestor,varredor);

  return 0;
}



Gestor* cria_gestor(int quantidade_max) {
  Gestor* novo_gestor = (Gestor*)malloc(sizeof(Gestor));

  novo_gestor->quantidade_max = quantidade_max;
  novo_gestor->quantidade_nos = 0;
  novo_gestor->inicio = NULL;
  novo_gestor->fim = NULL;
  return novo_gestor;
}

Node* cria_node(int valor) {
  char enter;
  Node* novo_node = (Node*)malloc(sizeof(Node));
  Aluno* aluno = (Aluno*)malloc(sizeof(Aluno));
  novo_node->proximo = NULL;
  novo_node->anterior = NULL;
  novo_node->valor = valor;

  leia_string(aluno->nome);
  printf("Digite a nota das provas : \n");
  scanf("%d %d %d", &aluno->p1, &aluno->p2, &aluno->p3);
  scanf("%c",&enter);
  aluno->media = (aluno->p1 + aluno->p2 + aluno->p3)/3;
  calcula_matricula(aluno,novo_node->valor);
  novo_node->aluno = aluno;
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

  }
}

void leia_string (char* palavra) {
  int i = 0;
  int j = 0;
  printf("Digite o nome do aluno : \n");
  while((palavra[i] = getchar()) != '\n') {
    i++;
  }
  while(palavra[j] != '\n') {
    j++;
  }
  palavra[j] = '\0';
}

void calcula_matricula (Aluno* aluno,int valor) {
  int primeiro = 0;
  int segundo = 1;
  int proximo = 0;
  int contador = 0;

  if(valor == 1 ) {
    aluno->matricula = 1;
  } else {
    for (; contador < valor; contador++) {
        if (contador <= 1) {
          proximo = contador;
        }
        else {
          proximo = primeiro + segundo;
          primeiro = segundo;
          segundo = proximo;
        }
    }
    aluno->matricula = (proximo + primeiro);
  }
}

void imprime_lista (Gestor* gestor, Node* varredor) {

    if(gestor->quantidade_nos <= 1) {
      printf("    %d \t \t    %s \t\t      %d ", varredor->aluno->matricula, varredor->aluno->nome, varredor->aluno->media);
      printf("\n------------------------------------------------------ \n");
    }
    else {
      printf("    %d \t \t    %s \t\t      %d ", varredor->aluno->matricula, varredor->aluno->nome, varredor->aluno->media);
      printf("\n------------------------------------------------------ \n");
      varredor = varredor->anterior;
      if (varredor != gestor->fim) {
          imprime_lista(gestor,varredor);
      }
    }
}
