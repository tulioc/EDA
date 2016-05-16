#include <stdio.h>
#include <stdlib.h>
#define N 10

typedef struct pilha Pilha;

struct pilha {
  int numero_elementos; // topo da pilha
  float vet[N];
};


Pilha* pilha_cria(void) {
  Pilha* nova_pilha = (Pilha*)malloc(sizeof(Pilha));
  nova_pilha->numero_elementos = 0;
  return nova_pilha;
}

void pilha_push(Pilha* pilha, float valor) {
  if (pilha->numero_elementos == N) {
    printf("Capacidade da pilha estourou. \n");
    exit(1);
  } else {
    pilha->vet[pilha->numero_elementos] = valor;
    pilha->numero_elementos++;
  }
}

float pilha_pop(Pilha* pilha) {
  float v;

  if (pilha->numero_elementos == 0) {
    printf("Pilha vazia\n");
    exit(1);
  } else {
    v = pilha->vet[pilha->numero_elementos-1];
    pilha->numero_elementos--;
    return v;
  }
}


void pilha_imprime (Pilha* pilha) {
  int varredor = 0;
  if (pilha->numero_elementos == 0) {
    printf("Pilha vazia\n");
  } else {
    for (; varredor < pilha->numero_elementos; varredor++) {
      printf("%f\n",pilha->vet[varredor]);

    }
    printf("\n Fim pilha \n");
  }
}

int main (void) {
  Pilha* teste;
  teste = pilha_cria();
  pilha_imprime(teste);
  pilha_push(teste, 5.0);
  pilha_imprime(teste);
  pilha_push(teste, 7.0);
  pilha_imprime(teste);
  pilha_push(teste, 6.0);
  pilha_imprime(teste);
  pilha_pop(teste);
  pilha_imprime(teste);



  return 0;
}
