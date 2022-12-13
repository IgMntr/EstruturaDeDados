#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct pessoa
{
	char nome[30];
	int idade, telefone;
};
typedef struct pessoa Pessoa;
void cadastroPessoa(Pessoa *pessoa_vet)
{
	int contador;
	for(contador = 0; contador < 5; contador++)
	{
		printf("\nentre com o nome:");
		scanf(" %[^\n]s", pessoa_vet[contador].nome);
		printf("entre com a idade:");
		scanf("%d", &pessoa_vet[contador].idade);
		printf("entre com o telefone:");
		scanf("%d", &pessoa_vet[contador].telefone);
	}
}
void alterarDados(Pessoa *pessoa_vet)
{
	int contador, i = 0;
	char nomeAltera[30];
	printf("insira o cadastro a ser alterado:");
	scanf("%s", nomeAltera);
	for(contador = 0; contador < 5; contador++)
	if(strcmp(nomeAltera, pessoa_vet[contador].nome) == 0)
			{
				printf("%s", pessoa_vet[contador].nome);
				printf("%d", pessoa_vet[contador].idade);
				printf("%d", pessoa_vet[contador].telefone);
				i = 1;	
			
	
	
		
}
void maioresde18(Pessoa *pessoa_vet)
{
	int contador;
	for(contador = 0; contador < 5; contador++)
	{
		if(pessoa_vet[contador].idade >= 18)
		{
			printf("\nnome:%s", pessoa_vet[contador].nome);
			printf("\nidade:%d", pessoa_vet[contador].idade);
			printf("\ntelefone:%d\n", pessoa_vet[contador].telefone);
		}		
	}
}
void pesquisaDados(Pessoa *pessoa_vet)
{
	int contador, posicao;
	char nomePesquisa[30];
	printf("insira o cadastro a ser pesquisado:");
	scanf(" %[^\n]s", nomePesquisa);
	for(contador = 0; contador < 5; contador++)
	{
		if(strcmp(nomePesquisa, pessoa_vet[contador].nome) == 0)
		{
			posicao = contador;
		}
	}
	printf("dados:\n");
	printf("nome:", pessoa_vet[0].nome);
	printf("\nidade:", pessoa_vet[0].idade);
	printf("\ntelefone:", pessoa_vet[0].telefone);
}
main(void)
{
	int opcao;
	Pessoa pessoa_vet[5];
	do
	{
		printf("\n(1)Cadastro\n(2)Alterar dados\n(3)Pesquisa de dados \n(4)Dados de maiores\n(5) Sair\n");
		scanf("%d", &opcao);
		if(opcao == 1)
		{
			system("cls");
			cadastroPessoa(&pessoa_vet);
		}
		else
		{
			if(opcao == 2)
		{
				system("cls");
				alterarDados(&pessoa_vet);
		}
			else
			{
				if(opcao == 3)
				{
					system("cls");
					pesquisaDados(&pessoa_vet);
				}
				else
				{
					if(opcao == 4)
					{
					system("cls");	
					maioresde18(&pessoa_vet);
					}
				}
			}
		}
	}
	while(opcao != 5);
} 
