#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
struct arvore
{
  char titulo[50], autor[100], editora[30];
  struct arvore *esquerda, *direita;
};

typedef struct arvore *pont_arvore;

int vazia (pont_arvore pont) 
{
  return (pont == NULL);
}

void inserir (pont_arvore *pont, char tit[], char aut[], char edit[])
{
  pont_arvore novo_no;
  if ((*pont) == NULL)
  {
    novo_no = (pont_arvore)malloc(sizeof(struct arvore));
    strcpy(novo_no->titulo, tit);
    strcpy(novo_no->autor, aut);
    strcpy(novo_no->editora, edit);
    novo_no->esquerda = NULL;
    novo_no->direita = NULL;
    (*pont) = novo_no;
  }
  else
  {
    if (strcmp(tit, (*pont)->titulo) < 0)
      inserir(&((*pont)->esquerda), tit, aut, edit);
    else
      inserir(&((*pont)->direita), tit, aut, edit);
  }
}

void contar_titulos (pont_arvore pont, char tit[], int *cont)
{
  if (pont != NULL)
  {
    if (strcmp(tit, pont->titulo) == 0)
    {
      	(*cont)++;
      	contar_titulos(pont->direita, tit, cont);
	}
	else
     if (strcmp(tit, pont->titulo) < 0)
      	contar_titulos(pont->esquerda, tit, cont);
     else
      	contar_titulos(pont->direita, tit, cont);
   }
}

pont_arvore getmax (pont_arvore pont)
{
   if (pont->direita == NULL)
    return(pont);
  else
    return(getmax(pont->direita));
}

void remover (pont_arvore *pont, char tit[])
{
  pont_arvore p, aux;
  if ((*pont) != NULL)
  {
   if (strcmp(tit, (*pont)->titulo) == 0)
   {
      p = (*pont);
      if ((*pont)->esquerda == NULL)
      {
         (*pont) = (*pont)->direita;
      }
      else
      {
	 	p = (*pont)->esquerda;
	 	aux = getmax(p);
	 	strcpy((*pont)->titulo,aux->titulo);
		if((p->direita == NULL) && (p->esquerda == NULL))
	 	{
	   		(*pont)->esquerda=NULL;
	 	}
		else
	 	{
	    	if (p->direita != NULL)
	   		{
	      		while (strcmp(tit, (*pont)->titulo) != 0)
	     		{
		 			p = p->direita;
	      		}
	      		if (aux->esquerda == NULL)
					p->direita = NULL;
	    		else
		 			p->direita = aux->esquerda;
	    	}
	    	else
	    	{
	      		(*pont)->esquerda = aux->esquerda;
	    	}
		}
		free(aux);
        aux = NULL;
      }
    }
    else
    {
      if (strcmp(tit, (*pont)->titulo) < 0)
    		remover(&((*pont)->esquerda), tit);
	  else
	     	remover(&((*pont)->direita), tit);
    }
  }
}

//Atravessando em pre-ordem.
void pre_ordem (pont_arvore pont)
{
   if (pont != NULL)
   {
     printf("%s\n",pont->titulo);
	 pre_ordem(pont->esquerda);
     pre_ordem(pont->direita);
   }
}

int main()
{
  pont_arvore raiz = NULL;
  int opcao, contador;
  char titulo[50], autor[100], editora[30];

  do
  {
    system("cls");
	printf("1- Inserir\n");
    printf("2- Exibir em pre-ordem\n");
    printf("3- Contar titulos na arvore\n");
    printf("4- Excluir\n");
    printf("5- Sair\n");
    printf("Digite a sua opcao: ");
    scanf("%d",&opcao);
    printf("\n");
    switch (opcao)
    {
      case 1: printf("Digite o titulo: ");
	      scanf("%s",titulo);
	      printf("Digite o autor: ");
	      scanf("%s",autor);
	      printf("Digite a editora: ");
	      scanf("%s",editora);
	      inserir(&raiz,titulo,autor,editora);
	      break;
      case 2: if (vazia(raiz))
      			printf("A arvore esta vazia!\n");
      		  else
	  			pre_ordem(raiz);
	      break;   
      case 3: if (vazia(raiz))
      			printf("A arvore esta vazia!\n");
      		  else
      		  {
	  	  		printf("Digite um titulo:");
	     		scanf("%s",titulo);
	     		contador = 0;
	      		contar_titulos(raiz,titulo,&contador);
				if (contador > 0)
					printf("Quantidade de vezes que o titulo aparece na arvore: %d \n",contador);
	      		else
					printf("Titulo nao encontrado!\n");
			  }
	      break;
	  case 4: if (vazia(raiz))
      			printf("A arvore esta vazia!\n");
      		  else
	  	      {
		  		printf("Digite um titulo:");
	      		scanf("%s",titulo);
	      		remover(&raiz,titulo);
	      	  }
	      break;
    }
    printf("\nTecle algo!");
	getch();
  }while (opcao!=5);
}

