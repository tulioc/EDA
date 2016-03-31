/*
 - Inserção é feita sempre ao final da lista, após o último processo pendente.
 - A remoção é feita através da troca dos identificadores do processo a ser removido com o processo que ocupa a última posição válida da lista encadeada. Após a permuta,
 o último elemento é removido.
 - A lista encadeada do sistema tem uma capacidade máxima de N processos pendentes. Caso uma inserção tente ser realizada com a lista completamente cheia,
 o processo a ser inserido deve ser descartado.
 - também deverá ser ignorada uma tentativa de remoção quando a lista de processos
 pendentes estiver vazia ou o identificador do processo fornecido não estiver presente na lista.


Entrada : A entrada consiste em uma única linha com capacidade N da lista, o número M de processos a serem carregados
na inicialização do sistema, seguidos pelos respectivos identificadores,
o número R de requisições de inserção e remoção e das descrições das mensagens de inserção e remoção
Todos os valores são separados por espaços em branco N.

Saída : A saída do programa deverá contar a mensagem : V = [id1,id2,...] onde id é o idenficador do i-ésimo processo
na lista encadeada. Cada identificador deve ser seguido de uma vírgula e um espaço em branco, exceto o último, e todos eles devem estar entre colchetes.

Entradas                    Saídas
10 2 1 2 1 3 n              V = [1, 2, 3]
10 3 3 1 2 3 3 t 4 n 5 n    V = [2, 1, 4, 5]

*/
#include <stdio.h>
#include  <stdlib.h>

typedef struct lista Lista;


struct lista {
  int id;
  Lista* proximo;

};

Lista* inserirElemento (Lista* lista, int id, int numMax);
Lista* criarLista(int id);
Lista* removerElemento(Lista* lista, int id);
int qntsElementos (Lista* lista);



int main (void) {


return 0;
}

Lista* removerElemento(Lista* lista, int id) {
  Lista* elementoAlvo;
  Lista* ultimoElemento;
  Lista* penultimoElemento;

  elementoAlvo = lista;
  penultimoElemento = lista;
  ultimoElemento = lista->proximo;

  while(ultimoElemento->proximo != NULL) {
    ultimoElemento = ultimoElemento->proximo;
    penultimoElemento = penultimoElemento->proximo;
  }

  while(elementoAlvo->id != id) {
    elementoAlvo = elementoAlvo->proximo;
  }
  penultimoElemento->proximo = NULL;
  int valorUltimoElemento;
  valorUltimoElemento = ultimoElemento->id;
  ultimoElemento->id = elementoAlvo->id;
  elementoAlvo->id = valorUltimoElemento;
  free(ultimoElemento);
  return lista;

}



int qntsElementos (Lista* lista) {

  int contador = 0;
  Lista* aux;
  aux = lista;
  while(aux != NULL) {
    aux = aux->proximo;
    contador = contador + 1;
  }
  return contador;
}




Lista* criarLista(int id) {
  Lista * primeiroElemento;
  primeiroElemento->id = id;
  primeiroElemento->proximo = NULL;
  return primeiroElemento;
}


Lista* inserirElemento (Lista* lista, int id, int numMax) {

    if (lista != NULL) {

    if (qntsElementos(lista) <= (numMax -1) ) {
      Lista* anterior;
      Lista* ultimo;
      anterior = lista;
      ultimo = lista->proximo;
        while (ultimo->proximo != NULL) {
          anterior = anterior->proximo;
          ultimo = ultimo->proximo;
        }
        Lista* novoElemento;
        novoElemento = (Lista*)malloc(sizeof(Lista));
        novoElemento->proximo = ultimo->proximo;
        anterior->proximo = novoElemento;
        novoElemento->id = id;
        free(ultimo);
        return lista;
      } else {
        printf("Lista cheia\n");
        }

    } else {
      printf("Tchau\n");
    }
}
