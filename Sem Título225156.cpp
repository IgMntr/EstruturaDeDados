#include<stdio.h>
int main()
{
	int n, elemento_vetor;
	scanf("%d", & elemento_vetor);
	for(elemento_vetor = 1; n > 1; n = n - 1)
	{
		elemento_vetor = elemento_vetor * n;
	}
	printf("%d", elemento_vetor);
	return elemento_vetor;
}
