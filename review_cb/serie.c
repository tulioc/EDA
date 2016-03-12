/*
Fazer um programa para calcular o valor de S para os N
primeiros termos da série abaixo.
S = 1!/2^3 + 3!/4^6 + 5!/6^9 + 7!/8^12 + ...
No cálculo do fatorial e da exponenciação, criar as funções
fatorial e power conforme a seguinte especificação:
• y = fatorial (n), onde fatorial calcula e retorna o fatorial
de n; y = inteiro longo e n é inteiro.
• y’ = power (n, e), onde power é a função que calcula o
resultado da operação de n elevado ao expoente e; n e
e são números inteiros positivos; y’ = inteiro longo.

*/

#include <stdio.h>
#include <math.h>


int fatorial (int valor);


int main () {

  int contador = 0;
  int n;
  float resultadoSerie = 0.0;


  printf("Digite quantos termos quer somar na série --> ((n*2)+1)! / ((n*2) +2)^( (n*3) + 3) \n");
  scanf("%d",&n);
  for (int contador = 0; contador < n; contador++) {
    /*
      A série pode ser descrita como  : ((n*2)+1)! / ((n*2) +2)^( (n*3) + 3)
    */
    resultadoSerie = resultadoSerie + fatorial( ( contador*2 ) +1 )/pow( ( (contador*2) + 2),( (contador*3) + 3) );

  }

printf ("O resultado da soma dos %d primeiros termos da série é : %f\n",n,resultadoSerie);



  return 0;
}



int fatorial (int valor) {
  int fatorial = 1;

  while( valor > 0 ) {
    fatorial = fatorial * valor;
    valor = valor -1;
  }

  return fatorial;
}
