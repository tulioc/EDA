#include <stdio.h>
#include  <stdlib.h>
typedef struct pessoa Pessoa;
typedef struct lista Lista;

struct pessoa {
  float massa;
  float altura;
  float imc;
};



struct lista {

  Pessoa *pessoa;
  Lista *proximo;

};





Lista* criaLista (void) {
  Lista* primeiroElemento = (Lista*)malloc(sizeof(Lista));
  Pessoa* pessoa = (Pessoa*)malloc(sizeof(Pessoa));
  primeiroElemento->pessoa = pessoa;
  primeiroElemento->proximo = NULL;
  return primeiroElemento;
}



Lista* adicionaElemento (Lista* lista) {
  Lista* novoElemento = (Lista*)malloc(sizeof(Lista));
  Pessoa* pessoa = (Pessoa*)malloc(sizeof(Pessoa));
  novoElemento->pessoa = pessoa;
  float massa;
  float altura;
  scanf(" %f %f ",&massa,&altura);
  novoElemento->pessoa->massa = massa;
  novoElemento->pessoa->altura = altura;
  novoElemento->pessoa->imc = massa/(altura* altura);
  novoElemento->proximo = lista;
  lista = novoElemento;
  return lista;
}


Lista* addPessoas (int numeroPessoas, Lista* lista) {
  int contador = 0;
  for (contador = 0; contador < numeroPessoas ; contador++) {
    if (contador == 0) {
      float massa;
      float altura;
      scanf(" %f %f ", &massa, &altura);
      lista->pessoa->massa = massa;
      lista->pessoa->altura = altura;
      lista->pessoa->imc = massa/(altura*altura);
    }

    if (contador > 0 ) {
      lista = adicionaElemento(lista);
    }
  }
  return lista;
}


Lista* organizaDecrescente(Lista* lista, int qntDeElementos) {

  Lista* aux1;
  Lista* aux2;
  int contador = 0;
  for (contador = 0; contador < qntDeElementos; contador++) {
    aux1 = lista;
    aux2 = lista->proximo;

    while (aux2 != NULL) {

      if(aux1->pessoa->imc < aux2->pessoa->imc) {
        float salva;
        salva = aux2->pessoa->imc;
        aux2->pessoa->imc = aux1->pessoa->imc;
        aux1->pessoa->imc = salva;
      } else {
        // nada
      }

      aux1 = aux1->proximo;
      aux2 = aux2->proximo;
    }
  }
  return lista;
}

void imprimeIMC (Lista* lista) {

    Lista* varredor;
    for (varredor = lista; varredor!= NULL; varredor = varredor->proximo) {
      printf("%.2f ", varredor->pessoa->imc);
    }
}





int main (void) {

  Lista* lista;
  lista = criaLista();
  int numeroPessoas;
  scanf("%d", &numeroPessoas);
  lista = addPessoas(numeroPessoas,lista);
  imprimeIMC(lista);



  return 0;
}
