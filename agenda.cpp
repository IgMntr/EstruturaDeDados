#include <stdio.h>
#include <string.h>

#define limite_maximo 100

struct tpessoa
	{
		char nome[100], telefone[15];
		int idade;
	};
typedef struct tpessoa Pessoa;

struct tagenda
	{
		Pessoa pessoas[limite_maximo];
		int total_pessoas;
	};
typedef struct tagenda Agenda;

void inserir (Agenda *agenda)
{
	int total;
	total = agenda->total_pessoas;
	while(strcmp("FIM", agenda->pessoas[total].nome))
	if (total < limite_maximo)
	{
		printf("\n Digite o seu nome : ");
		scanf("%s",agenda->pessoas[total].nome);
		printf("\n Digite o seu telefone : ");
		scanf("%s",agenda->pessoas[total].telefone);
		printf("\n Digite a sua idade : ");
		scanf("%d",&agenda->pessoas[total].idade);
		total++;
		agenda->total_pessoas = total;
		printf("\n Dados inseridos! \n");
	}
	else
	{
		printf("\n Agenda cheia!! \n");
	}
}

void alterar (Agenda *agenda)
{
	int i = 0, cont = 0;
	char nomePesquisa[50];
	printf("digite o nome a ser pesquisado:");
	scanf("%s", nomePesquisa);
	if(agenda->total_pessoas > 0)
	{
		while((cont < agenda->total_pessoas) && (! achou)
		{
			if(strcmp(agenda->pessoas[cont].nome, nomePesquisa) == 0)
			{
				printf("\n digite o novo nome :");
				scanf("%s",agenda->pessoas[cont].nome);
				printf("\n entre com o novo telefone:");
				scanf("%s", agenda->pessoas[cont].telefone);
				printf("\n entre com a nova idade:");
				scanf("%d", agenda->pessoas[cont].idade);
				i = 1;
			}
			else
			{
				cont++;
			}
			if (! i)
			{
				printf("\n O nome nao foi encontrado na agenda. \n");
			}
		}
	}
}
void ordena
	
