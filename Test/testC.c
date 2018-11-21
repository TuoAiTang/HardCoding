#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
	int start;
	int end;
} Interval;

int main(){

	int a = 3;
	(*(&a))++;
	printf("%d\n", a);

	printf("I love coding!\n");
	return 0;
}