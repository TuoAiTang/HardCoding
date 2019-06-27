#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
	int start;
	int end;
} Interval;


void checkEndian(){
	int a = 0x12345678;
	char* c = (char*) &a;
	if(*c == 0x78)
		printf("小端\n");
	else
		printf("大端\n");
}
int main(){
	// double d = 3.14;
	// int* dp = (int*) &d;
	// *(dp) = 1073741824;
	// printf("%.14f\n", d);
	// printf("I LOVE CODING VERY MUCH!!!!\n\n");
	printf(20 % 30);
	return 0;
}


