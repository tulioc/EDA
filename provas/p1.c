#include <stdlib.h>
#include <stdio.h>

typedef struct no
{
  int id;
  struct no * anterior;
  struct no * proximo;
} node;

typedef struct cabecalho
{
  int quantidade_nos;
  int qtd_max;
  node * inicio;
  node * fim;
} head;

head * criaHead(int max)
{
  head * novoHead = (head*)malloc(sizeof(head));

  novoHead->quantidade_nos = 0;
  novoHead->qtd_max = max;
  novoHead->inicio = NULL;
  novoHead->fim = NULL;

  return novoHead;
}

node * criaNode(int valorId)
{
  node * novoNode = (node*)malloc(sizeof(node));

  novoNode->id = valorId;
  novoNode->proximo = NULL;
  novoNode->anterior = NULL;

  return novoNode;
}

void insereProcesso(head * cabe, int valorId)
{
  node * novoNode = criaNode(valorId);

  if(cabe->quantidade_nos == 0)
  {
    cabe->inicio = novoNode;
    cabe->fim = novoNode;

    cabe->quantidade_nos++;
  } else if(cabe->quantidade_nos > 0 && cabe->quantidade_nos <
              cabe->qtd_max)
  {
    novoNode->anterior = cabe->fim;
    cabe->fim->proximo = novoNode;

    cabe->fim = novoNode;
    cabe->quantidade_nos++;
  } else
  {
    //NADA - NAO MEXA - VSF
  }
}

node * buscaID(head * cabe, int alvo)
{
  node * varredor = cabe->inicio;
  int achou = 0;
  while(varredor->id != alvo && varredor->proximo != NULL)
  {
    varredor = varredor->proximo;
  }
  if(varredor->id == alvo)
  {
    return varredor;
  } else
  {
    return NULL;
  }
}


void removeId(head * cabe, int id)
{
  node * noAchado = buscaID(cabe, id);


  if(noAchado != NULL)
  {
    if(noAchado == cabe->fim)
    {
      cabe->fim = noAchado->anterior;
      cabe->fim->proximo = NULL;
      cabe->quantidade_nos--;

      free(noAchado);
    } else
    {
      int salvaID = cabe->fim->id;

      cabe->fim->id = noAchado->id;
      noAchado->id = salvaID;

      cabe->fim = noAchado->anterior;
      cabe->fim->proximo = NULL;
      cabe->quantidade_nos--;
    }
  } else
  {
    return;
  }
}
/*
void imprimeLista(head * lista)
{
  int contador = 0;
  node * auxiliar = lista->inicio;

  for(; contador < lista->quantidade_nos; contador++)
  {
    printf("%d ");
  }
}
*/
int main(void)
{



  return 0;
}
