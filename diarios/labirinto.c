#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX 100
typedef int tipo_tem;
#define N 40
#define LIVRE 0
#define PAREDE 32767






void cria (int L [N][N]) {
  int i;
  int j;
  for (i = 0; i < N; i++) {
    L [i] [0] = PAREDE;
    L [i] [N - 1] = PAREDE;
  }

  for (j = 0; j < N; j++) {
    L[0][j] = PAREDE;
    L[N-1][j] = PAREDE;
  }

  for (i = 1; i < N-1; i++)
    for (j = 1; j < (N - 1); j++)
      if( rand() % 3 == 0) L[i][j] = PAREDE;
      else L[i][j] = LIVRE;
  L[1][1] = LIVRE;
  L[N - 2][N - 2] = LIVRE;
}

void exibe (int L[N][N]) {
  int i;
  int j;

  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++)
      switch (L[i][j]) {
        case LIVRE: putchar (' '); break;
        case PAREDE: putchar ('#'); break;
        default: putchar(126);
      }
    printf("\n");
  }
}

int anota (int L[N][N]) {
  int fila [MAX];
  int *distancias;
  int contador = 0;
  int i,j;
  int inicio = 0;
  int fim  = 0;
  distancias = malloc(100*sizeof(int));
  L [1][1] = 1;
  fila[inicio] = L[1][1];
  while(fila!= NULL) {
    
  }

}




int main (void) {

  int labirinto[N][N];
  char r;
  srand (time(NULL));
  do {
    system ("cls");
    cria(labirinto);
    exibe(labirinto);
    printf("Continua ? (s/n) ");
    scanf("%c%*c",&r);
  } while (toupper(r) != 'N');

  return 0;
}
