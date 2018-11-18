#include <stdio.h>
#include <stdlib.h>

void print(int n){
	int m = n / 10;

	if(m > 0)
		print(m);

	printf("%d", n % 10);
}


int main(){
	int n = 4716;
	print(n);


	return 0;
}