#include<stdio.h>


int soma(int x) 
{
    if (x > 0) 
	{
		return (x + soma(x - 2));
	}
	else return x;
	
}
int main()
{
	int x, result;
	scanf("%d", &x);
	if(x % 2 != 0)
	{
		x = x - 1;
	}
	result = soma(x);
	printf("%d", result);
	return 0;
}
