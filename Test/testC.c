#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
	int start;
	int end;
} Interval;

int main(){

	// int* a = (int*)malloc(5 * sizeof(int));
	// memset(a, -1, 5 * sizeof(int));
	// for(int i = 0; i < 5; i++)
	// 	printf("%d\n", a[i]);

	double n = 1;
	for(int i = 35; i >= 26; i--)
		n *= i;
	double n1 = 1, n9 = 1, n10 = 1;
	for(int i = 0; i < 10; i++){
		n10 *= (i + 1);
		n1 *= 0.1;
	}
	for(int i = 0; i < 20; i++)
		n9 *= 0.9;


	printf("%f\n", n * n1 * n9 / n10);
	printf("I LOVE CODING VERY MUCH!!!!\n\n");
	return 0;
}