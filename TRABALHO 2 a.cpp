#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct tno
{
   char nome[30];
   int codigo;
   float preco;
   struct tno *proximo;
};

struct tlista
{
   struct tno *primeiro, *ultimo;
};

typedef struct tno TNo;
typedef struct tlista TLista;

void inicializar (TLista *pontlista)
{
  pontlista->primeiro = NULL;
  pontlista->ultimo = NULL;
}

void inserir (TLista *pontlista, int codigo, float preco, char nome[])
{
  TNo *novo_no;

  novo_no = (TNo*)malloc(sizeof(TNo));
  novo_no->codigo = codigo;
  novo_no->preco = preco;
  novo_no->proximo = NULL;
  strcpy(novo_no->nome,nome);
  if (pontlista->primeiro == NULL)
  {
	pontlista->primeiro = novo_no;
    pontlista->ultimo = novo_no;
  }
  else
  {
    pontlista->ultimo->proximo = novo_no;
    pontlista->ultimo = novo_no;
  }
  printf("O produto foi inserido!\n");
}
int pesquisa (TLista *pontlista, char nome[], float preco)
{
	TNo *no_aux;
	int achou = 0, opcao;
	printf("para pesquisar o nome digite 1 e para pesquisar o preco digite 2");
	scanf("%d", &opcao);
	if(opcao == 1)
	{
		if (! (pontlista->primeiro == NULL))
	  	{
		    no_aux = pontlista->primeiro;
		    while ((! achou) && (no_aux != NULL))
	    	{
		    	if (strcmp(no_aux->nome, nome) == 0)
		    	{
					printf("%s\n", no_aux->nome);
					printf("%f\n", no_aux->preco);
					printf("%d\n", no_aux->codigo);
					achou = 1;
		    	}
		    	else
		    	{
					no_aux = no_aux->proximo;
		    	}
	    	}
	  	}
	  	return(achou);
	}
	else
	{
		if (! (pontlista->primeiro == NULL))
		  	{
			    no_aux = pontlista->primeiro;
			    while ((! achou) && (no_aux != NULL))
		    	{
			    	if (no_aux->preco == preco)
			    	{
						printf("%s\n", no_aux->nome);
						printf("%f\n", no_aux->preco);
						printf("%d\n", no_aux->codigo);
						achou = 1;
			    	}
			    	else
			    	{
						no_aux = no_aux->proximo;
			    	}
		    	}
		  	}
		  	return(achou);
	}
}
int alterar (TLista *pontlista, int codigo)
{
  int achou=0;
  TNo *no_aux;

  if (! (pontlista->primeiro == NULL))
  {
    no_aux = pontlista->primeiro;
    while ((! achou) && (no_aux != NULL))
    {
      if (no_aux->codigo == codigo)
      {
	    achou = 1;
	    printf("Digite o novo nome do produto : ");
	    scanf("%s",no_aux->nome);	
	  	printf("Digite o novo preco do produto : ");
	    scanf("%f",&no_aux->preco);	
	  } 
      else
      {
	    no_aux = no_aux->proximo;
      }
    }
  }
  return(achou);
}
void exibir (TLista *pontlista)
{
  TNo *no_aux;

  if (pontlista->primeiro == NULL)
  {
     printf("A lista esta vazia!\n");
  }
  else
  {
    no_aux = pontlista->primeiro;
    while (no_aux != NULL)
    {
      printf("%s\n",no_aux->nome);
      printf("%d\n",no_aux->codigo);
	  printf("%f\n",no_aux->preco);
	  no_aux = no_aux->proximo;
    }
  }
}
void remover (TLista *pontlista, int valor)
{
  TNo *no_aux1, *no_aux2, *no_aux3;
  int achou;

  if (! (pontlista->primeiro == NULL))
  {
	  // Se o numero a ser excluido for o primeiro.
	  if (pontlista->primeiro->codigo == valor)
	  {
	    no_aux1 = pontlista->primeiro;
	    pontlista->primeiro = pontlista->primeiro->proximo;
	    free(no_aux1);
	    printf("O numero foi excluido!\n");
	  }
	  else
	  {
	    // Se o numero a ser excluido for o ultimo.
	    if ((pontlista->ultimo)->codigo == valor)
	    {
	      no_aux1 = pontlista->primeiro;
	      while (no_aux1->proximo != pontlista->ultimo)
	      {
			no_aux1 = no_aux1->proximo;
	      }
	      no_aux2 = pontlista->ultimo;
	      pontlista->ultimo = no_aux1;
	      pontlista->ultimo->proximo = NULL;
	      free(no_aux2);
	      printf("O numero foi excluido!\n");
	    }
	    else
	    {
	      // Se o numero a ser excluido estiver no meio da lista.
	      no_aux1 = pontlista->primeiro;
	      no_aux2 = pontlista->primeiro->proximo;
	      achou = 0;
	      while ((! achou) && (no_aux2 != NULL))
	      {
			if (no_aux2->codigo == valor)
			{
		  		achou = 1;
		 		no_aux3 = no_aux2;
		  		no_aux2 = no_aux2->proximo;
			}
			else
			{
		  		no_aux1 = no_aux1->proximo;
		  		no_aux2 = no_aux2->proximo;
			}
	      }
	      if (achou)
	      {
			no_aux1->proximo = no_aux2;
			free(no_aux3);
			printf("O numero foi excluido!\n");
	      }
	      else
	      {
			printf("O numero nao foi encontrado!\n");
	      }
	    }
	  }
  }
}
int main ()
{
  TLista lista;
  float p;
  int opcao, num;
  char str[30];
  inicializar(&lista);
  do
  {
    system("cls");
	printf("1 - INSERIR NO INICIO\n");
	printf("2 - REMOVER\n");
    printf("3 - CONSULTAR\n");
    printf("4 - EXIBIR\n");
    printf("5 - FIM\n");
    printf("Digite a sua opcao : ");
    scanf("%d",&opcao);
    switch (opcao)
    {
      	case 1 : printf("Digite os dados do produto a ser inserido no inicio da lista : ");
	       scanf("%s",str);
		   scanf("%",&p);
		   scanf("%d",&num);
	       inserir(&lista,num,p,str);
	       break;
		case 2 : printf("Digite o codigo do produto a ser removido : ");
	       scanf("%d",&num);
	       remover(&lista,num);
	       break;
      	case 3 : printf("Qual o codigo ou nome procurado ? ");
	       scanf("%s", str);
		   scanf("%d",&num);
	       pesquisa(&lista,num,str[])
	       break;
      	case 4 : exibir(&lista);
	       break;
    }
    
  }while(opcao!=5);
}










