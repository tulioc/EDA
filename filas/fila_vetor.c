#include <stdio.h>
#include <stdlib.h>
#define N 10


typedef struct fila Fila;


struct fila {
  int pos_ini;
  int n_elementos;
  float vetor[N];
};


Fila* cria_fila(void) {
  Fila* nova_fila = (Fila*)malloc(sizeof(Fila));
  nova_fila->pos_ini = 0;
  nova_fila->n_elementos = 0;
  return nova_fila;
}

void fila_add(Fila* fila, float valor) {
  int fim;
  fim = (fila->pos_ini + fila->n_elementos) % N;
  fila->vetor[fim] = valor;
  fila->n_elementos++;
}

float fila_delete(Fila* fila) {
  float v;
  if (fila->n_elementos == 0) {
    printf("Fila vazia\n");
  } else {
    v = fila->vetor[fila->pos_ini];
    fila->pos_ini = (fila->pos_ini + 1) % N;
    fila->n_elementos--;
    return v;
  }
}

void imprime_fila(Fila* fila) {
  int contador, fim;
  fim = (fila->pos_ini + fila->n_elementos) % N;
  contador = fila->pos_ini;
  for(; contador < fim; contador++) {
    printf("%.2f\n", fila->vetor[contador]);
  }
}


int main (void) {

  Fila* teste;
  teste = cria_fila();
  fila_add(teste, 1);
  fila_add(teste, 2);
  fila_add(teste, 3);
  fila_add(teste, 4);
  imprime_fila(teste);
  fila_delete(teste);
  imprime_fila(teste);
  return 0;
}
