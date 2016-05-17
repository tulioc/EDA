#include <stdio.h>
#include <stdlib.h>
#define N 10

typedef struct pilha Pilha;


struct pilha {
  int topo;
  float vetor[N];
};


Pilha* cria_pilha(void) {
  Pilha* nova_pilha = (Pilha*)malloc(sizeof(Pilha));
  nova_pilha->topo = 0;
  return nova_pilha;
}

void pilha_add(Pilha* pilha, float valor) {
  pilha->vetor[pilha->topo] = valor;
  pilha->topo++;
}

float pilha_delete(Pilha* pilha) {
  float v;
  if (pilha->topo == 0) {
    printf("Pilha vazia\n");
  } else {
    v = pilha->vetor[pilha->topo - 1];
    pilha->topo--;
    return v;
  }
}

void imprime_pilha(Pilha* pilha) {
  int contador =0;
  for (; contador < pilha->topo; contador++) {
    printf("%.2f\n",pilha->vetor[contador] );
  }
}

int main (void) {

    Pilha* teste;
    teste = cria_pilha();
    pilha_add(teste,1);
    pilha_add(teste,2);
    pilha_add(teste,3);
    imprime_pilha(teste);
    pilha_delete(teste);
    imprime_pilha(teste);

}
