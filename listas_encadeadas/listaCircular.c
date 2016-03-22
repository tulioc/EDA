#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;

struct lista {
  int valor;
  Lista *proximo;
};

Lista* criaPrimeiroElemento(int valorRecebido);
Lista* inserirValorListaCircular(Lista* lista, int valorRecebido);
void imprimirListaCircular(Lista* lista);


int main (void) {

  Lista* lista;
  lista = criaPrimeiroElemento(20);
  lista = inserirValorListaCircular(lista,30);
  lista = inserirValorListaCircular(lista,15);
  imprimirListaCircular(lista);
  return 0;
}

Lista* criaPrimeiroElemento(int valorRecebido) {
  Lista* lista;
  lista = (Lista*) malloc(sizeof(Lista));
  lista->valor = valorRecebido;
  lista->proximo = NULL;
  return lista;
}

Lista* inserirValorListaCircular(Lista* lista, int valorRecebido) {

  if(lista->proximo == NULL) {
    Lista* novoElemento = (Lista*) malloc(sizeof(Lista));
    novoElemento->valor = valorRecebido;
    novoElemento->proximo = lista;
    lista->proximo = novoElemento;
    return novoElemento;
  } else {
    Lista* novoElemento = (Lista*) malloc(sizeof(Lista));
    novoElemento->valor = valorRecebido;
    novoElemento->proximo = lista;
    Lista* varredor;
    varredor = lista;
    while(varredor->proximo != lista) {
      varredor = varredor->proximo;
    }
    varredor->proximo = novoElemento;
    return novoElemento;
  }



}

void imprimirListaCircular(Lista* lista) {

  Lista* varredor;
  for (varredor = lista; varredor!= NULL; varredor = varredor->proximo) {
    printf("Valor : %d\n", varredor->valor);
  }

}

















/*#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
  int numeroLegal;
  no * proximoNo;
} node;

node * geraNovoNo(int x)
{
  node * novoNo = (node*)malloc(sizeof(node));
  novoNo->numeroLegal = x;
  novoNo->proximoNo = NULL;
  return novoNo;
}

void adicionaNo(node * lista, int x)
{
  if(lista == NULL)
  {
    lista = gera
  }
}
*/
