#include <stdio.h>
#include <stdlib.h>
// Lista Circular Duplamente Encadeada.


typedef struct lista Lista;

struct lista {
  int valor;
  struct lista* anterior;
  struct lista* proximo;
};

Lista* criaPrimeiroElemento(int valorRecebido);
Lista* insereValorLista(Lista* lista, int valorRecebido);
void imprimirLista(Lista* lista);



int main (void) {

  Lista* lista;
  lista = criaPrimeiroElemento(20);
  lista = insereValorLista(lista,30);
  lista = insereValorLista(lista,45);
  lista = insereValorLista(lista,23);
  lista = insereValorLista(lista,12);
  imprimirLista(lista);


  return 0;
}



Lista* criaPrimeiroElemento(int valorRecebido) {
  Lista* lista;
  lista = (Lista*) malloc(sizeof(Lista));
  lista->valor = valorRecebido;
  lista->anterior = NULL;
  lista->proximo = NULL;
  return lista;
}

Lista* insereValorLista(Lista* lista, int valorRecebido) {
  if(lista->proximo == NULL) {
    Lista* novoElemento = (Lista*) malloc(sizeof(Lista)); // Alocando espaço na memória para o novo elemento da lista.
    novoElemento->valor = valorRecebido; // O valor do novo elemento da lista irá receber o valor recebido como parâmetro.
    novoElemento->proximo = lista; // O novo elemento irá apontar para o mesmo elemento que lista aponta.
    lista->proximo = novoElemento; // O primeiro elemento, que apontava para NULL, agora irá apontar para o novo elemento adicionado, criando assim, a lista circular.
    return novoElemento; // Retorna o novo elemento como "Cabeça da lista".
  } else { // Caso o a lista não tenha um único elemento, ela entra no else.
    Lista* novoElemento = (Lista*) malloc(sizeof(Lista)); // Alocando espaço na memória para o novo elemento da lista.
    novoElemento->valor = valorRecebido; // O valor do novo elemento da lista irá receber o valor recebido como parâmitro.
    novoElemento->proximo = lista; // O novo elemento irá apontar para o mesmo elemento que lista aponta.
    Lista* varredor; // Declarando um ponteiro auxiliar para varrer a lista.
    varredor = lista; // O ponteiro varredor, inicialmente, irá apontar para o mesmo elemento que lista aponta.
    while(varredor->proximo != lista) { // Enquanto o varredor não chegar no último elemento
      varredor = varredor->proximo; //varredor receberá o próximo elemento.
    }
    varredor->proximo = novoElemento; // Assim que ele encontra o último elemento, ele faz com que o último elemento aponte para o primeiro, dando continuidade a lista circular.
    return novoElemento; // Retorna o novo elemento como "Cabeça da lista"
  }
}

void imprimirLista (Lista* lista) {
  Lista* varredor;
  for (varredor = lista; varredor!= NULL; varredor = varredor->proximo) {
    printf("Valor : %d\n", varredor->valor);
  }
}
