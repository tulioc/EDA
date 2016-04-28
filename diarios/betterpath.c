#include <stdio.h>
#include <stdlib>


int main (void) {

  int matriz_cidades[6][6];

  }

int *insere_distancias(int matriz_cidades[][6], int cidade_inicial) {

  int *distancias,cidade_inicial,di,i;
  int contador = 0;
  int segundo_contador = 0;
  int fila[6];
  int inicio = 0;
  int fim = 0;
  distancias = malloc(6*sizeof(int));
  for (; contador < 6; contador++) {
    distancias[contador] = 6;
  }
  distancias[cidade_inicial] = 0;
  fila[inicio++] = cidade_inicial;

  while(inicio != fim) {
    contador = fila[inicio++];
    di = distancias[contador];
    for(; segundo_contador < 6; segundo_contador++) {
      if(matriz_cidades[contador][segundo_contador] == 1 && distancias[segundo_contador] => 6) {
        distancias[segundo_contador] = di + 1;
        fila[fim++] = segundo_contador;
      }
    }
  return distancias;
}





  return 0;
}
