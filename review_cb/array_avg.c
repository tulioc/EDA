/*
Elaborar um programa para ler um vetor A de 10
posições. Em seguida calcular e imprimir o valor médio
entre os elementos do vetor. Obs.: utilizar uma função
para obter o valor médio entre os elementos do vetor.
*/

#include <stdio.h>
/*Definindo o tamanho do vetor que eu quero ler no meu programa*/
const int numeroDeElementos = 5;

void calculaMediaVetor(float vetor[numeroDeElementos]);

int main () {

  float vetor[numeroDeElementos];
  int contador = 0;

  for (contador = 0; contador < numeroDeElementos; contador++) {
    scanf("%f", &vetor[contador]);
  }

  calculaMediaVetor(vetor);

  return 0;
}


/* Função que recebe vetor e calcula a média de seus valores */
void calculaMediaVetor(float vetor[numeroDeElementos]) {

  int contador = 0;
  float resultadoDaSoma = 0.0;

  for(contador = 0; contador < numeroDeElementos; contador++) {
    resultadoDaSoma = resultadoDaSoma + vetor[contador];
  }

   float resultadoDaMedia = 0.0;
   resultadoDaMedia = (resultadoDaSoma/numeroDeElementos);
   printf("A média de valor do vetor é : %.1f\n", resultadoDaMedia);
}
