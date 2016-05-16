#include  <stdio.h>
#include <stdlib.h>
#define N 10
typedef struct fila Fila;

struct fila {
  int numero_elementos; // NUMERO DE ELEMENTOS
  int pos_ini; // POSIÇÃO DO PROXIMO A SER REMOVIDO
  float vet[N];
};

Fila* fila_cria(void) {
  Fila* nova_fila = (Fila*)malloc(sizeof(Fila));
  nova_fila->numero_elementos = 0;
  nova_fila->pos_ini = 0;
  return nova_fila;
}

void fila_insere(Fila* fila, float valor) {
  int fim;
  if (fila->numero_elementos == N) {
    printf("Fila cheia \n");
    exit(1);
  }
  fim = (fila->pos_ini + fila->numero_elementos) % N;
  fila->vet[fim] = valor;
  fila->numero_elementos++;
}

float fila_retira (Fila* fila) {
  float valor;
  if (fila->numero_elementos == 0) {
    printf("Fila vazia.\n");
    exit(1);
  }
  valor = fila->vet[fila->pos_ini];

  fila->pos_ini = (fila->pos_ini + 1) % N;
  fila->numero_elementos--;
  return valor;
}

void imprime_fila (Fila* fila) {
  int varredor = fila->pos_ini;
  int fim;
  fim = fim = (fila->pos_ini + fila->numero_elementos) % N;
  if (fila->numero_elementos == 0) {
    printf("Fila Vazia\n");
  } else {
    printf("\n ===== INICIO FILA ===== \n");
    for (; varredor < fim; varredor++) {
      printf("%.2f\n", fila->vet[varredor]);
    }
    printf("\n ===== FIM FILA ===== \n");
  }
}


int main (void) {
  Fila* teste;
  teste = fila_cria();
  imprime_fila(teste);
  fila_insere(teste,1);
  fila_insere(teste,2);
  fila_insere(teste,3);
  fila_insere(teste,4);
  fila_insere(teste,5);
  imprime_fila(teste);
  fila_retira(teste);
  imprime_fila(teste);

  return 0;
}
