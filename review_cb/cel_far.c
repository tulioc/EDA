/*Fazer um algoritmo para converter temperaturas de
graus Celsius para Fahrenheit. No programa, a função
principal (main) deve solicitar valores de temperatura
em Celsius e imprimir o equivalente em Fahrenheit até
que o usuário digite uma temperatura igual a “9999”. O
processo de conversão para Fahrenheit deve ocorrer
dentro de uma função.*/

#include <stdio.h>

float celciusParaFahrenheit (float celcius) {

  float fahrenheit = 0.0;
  fahrenheit = (celcius/5)*9 + 32;

  return fahrenheit;
}



int main () {

  float valorCelcius = 0.0;

  while (valorCelcius != 9999.0) {

    printf("Conversor de Celsius para Fahrenheit, digite um valor em Celcius : \n");
    scanf("%f",&valorCelcius);

    if (valorCelcius == 9999.0) {
      printf("Programa Encerrado \n");
    }
    else {
      printf("O valor em Fahrenheit é : %f \n",celciusParaFahrenheit(valorCelcius));
      printf("=============================================================\n");
    }
  }

  return 0;
}
