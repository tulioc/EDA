#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;

struct lista {
  int valor;
  Lista* proximo;
};

Lista* criaLista(int valorRecebido);
Lista* insereElementoLista(Lista* lista, int valorRecebido);
Lista* booblesort(Lista* lista, int qntDeElementos);
int qntElementos(Lista* lista);
void imprimirLista(Lista* lista);

int main (void) {
Lista* lista;
lista = criaLista(12);
lista = insereElementoLista(lista,15);
lista = insereElementoLista(lista,8);
lista = insereElementoLista(lista,2);
lista = insereElementoLista(lista,56);
lista = insereElementoLista(lista,1);
imprimirLista(lista);
printf("Numero de elementos : %d", qntElementos(lista));
lista = booblesort(lista, qntElementos(lista));
printf("\n");
imprimirLista(lista);


  return 0;
}


Lista* criaLista(int valorRecebido) {
  Lista* primeiroElemento;
  primeiroElemento = (Lista*)malloc(sizeof(Lista));
  primeiroElemento->valor = valorRecebido;
  primeiroElemento->proximo = NULL;
  return primeiroElemento;
}

Lista* insereElementoLista(Lista* lista, int valorRecebido) {
  Lista* novoElemento;
  novoElemento = (Lista*)malloc(sizeof(Lista));
  novoElemento->valor = valorRecebido;
  novoElemento->proximo = lista;
  return novoElemento;
}


Lista* booblesort(Lista* lista, int qntDeElementos) {

    Lista* aux1;
    Lista* aux2;
    int contador = 0;
    for (contador = 0; contador < qntDeElementos; contador++) {
      aux1 = lista;
      aux2 = lista->proximo;

      while (aux2 != NULL) {

        if(aux1->valor > aux2->valor) {
          int salva;
          salva = aux2->valor;
          aux2->valor = aux1->valor;
          aux1->valor = salva;
        } else {
          // nada
        }

        aux1 = aux1->proximo;
        aux2 = aux2->proximo;
      }
    }
    return lista;
}

void imprimirLista (Lista* lista) {
  Lista* varredor;
  for (varredor = lista; varredor!= NULL; varredor = varredor->proximo) {
    printf("Valor : %d\n", varredor->valor);
  }
}

int qntElementos(Lista* lista) {
  int elementos = 0;
  Lista* varredor;

  for(varredor = lista; varredor!= NULL; varredor = varredor->proximo) {
    elementos++;
  }

  return elementos;
}
