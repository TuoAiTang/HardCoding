#include <stdio.h>
#include <stdlib.h>


int main()
{
	int a = 3, b = 2;
	int* pa = &a, *pb = &b;
	int **ppa = &pa, **ppb = &pb;

	a = b;
	b = 4;
	printf("%d\n", a);

	
	pa = pb;
	printf("%d\n", a);

	**ppa = 4;
	pa = pb;
	printf("%d\n", a);

	return 0;
}