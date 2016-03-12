/* Fazer um programa C para ler uma matriz A de 4
linhas e 4 colunas com números inteiros. Em seguida,
criar uma função para descobrir e retornar a soma
entre os elementos que estão abaixo da diagonal
principal de A. O valor retornado deve ser impresso
pelo programa principal.
*/

#include <stdio.h>
/*
O programa realizado só funciona com matrizes 4x4, seria necessário manipular ponteiros para fazer com matrizes de qualquer tamanho.
*/
const int linhas = 4;
const int colunas = 4;

void somaAbaixoDaDiagonalPrincipal(int vetor[linhas][colunas]);



int main () {

  int vetor[linhas][colunas];
  int contadorLinhas = 0;
  int contadorColunas = 0;

  /* Leitura dos 16 valores da matriz*/
  for (contadorLinhas = 0; contadorLinhas < linhas; contadorLinhas++) {
    for (contadorColunas = 0; contadorColunas < colunas; contadorColunas++) {
      scanf("%d", &vetor[contadorLinhas][contadorColunas]);
    }
  }

  somaAbaixoDaDiagonalPrincipal(vetor);

  return 0;
}

/* Função que faz a soma dos elementos abaixo da Diagonal Principal da matriz 4x4*/
void somaAbaixoDaDiagonalPrincipal(int vetor[linhas][colunas]) {

  int contador = 0;
  int resultadoPrimeiraColuna = 0;
  int resultadoSegundaColuna = 0;


  for(contador = 1; contador <= (colunas - 1); contador++ ) {
    resultadoPrimeiraColuna = resultadoPrimeiraColuna + vetor[contador][0];
  }

  for(contador = 2; contador <= (colunas - 1); contador++ ) {
    resultadoSegundaColuna = resultadoSegundaColuna + vetor[contador][1];
  }

  int resultadoFinal = 0;
  int ultimoValor = 0;
  ultimoValor = vetor[3][2];
  resultadoFinal = resultadoPrimeiraColuna + resultadoSegundaColuna + ultimoValor;

  printf("A soma dos valores abaixo da diagonal principal da matriz é : %d \n",resultadoFinal);

}
