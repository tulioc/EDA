#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;

struct lista {
  int valor;
  Lista *proximo;
};


// Declarando esqueleto das funções
Lista* criaPrimeiroElemento(int valorRecebido);
Lista* inserirValorListaCircular(Lista* lista, int valorRecebido);
void imprimirListaCircular(Lista* lista);

// Main
int main (void) {

  Lista* lista;
  lista = criaPrimeiroElemento(20);
  lista = inserirValorListaCircular(lista,30);
  lista = inserirValorListaCircular(lista,15);
  imprimirListaCircular(lista);
  return 0;

}

// =========== Implementação das funções ==============



// Função que cria o primeiro nó da lista, nó que aponta para NULL.
Lista* criaPrimeiroElemento(int valorRecebido) {
  Lista* lista;
  lista = (Lista*) malloc(sizeof(Lista)); // Alocando espaço na memória para o primeiro elemento.
  lista->valor = valorRecebido; // O valor do primeiro elemento será o valor recebido como parâmetro na função.
  lista->proximo = NULL; // O primeiro elemento irá apontar para NULL.
  return lista; // A função retorna o ponteiro para o primeiro elemento.
}


// Função que insere valores na lista circular simples
Lista* inserirValorListaCircular(Lista* lista, int valorRecebido) {

  // Se a função receber uma lista, com um único elemento, ela entra no IF.
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
// Função que imprime o valor dos elementos da lista.
void imprimirListaCircular(Lista* lista) {

  Lista* varredor;
  for (varredor = lista; varredor!= NULL; varredor = varredor->proximo) {
    printf("Valor : %d\n", varredor->valor);
  }

}
