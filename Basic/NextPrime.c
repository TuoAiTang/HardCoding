#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int nextPrime(int num){
	if(num == 1)
		return 2;
	if(num == 2)
		return 3;
	int is_prime;
	if(num % 2 == 0)
		num--;

	do
	{
		is_prime = 1;
		num = num + 2;
		//ensure next num is even number
		for(int i = 2; i <= sqrt(num); i++){
			if(num % i == 0){
				is_prime = 0;
				break;
			}
		}
	}while(is_prime == 0);

	return num;
}

int main()
{
	
	
	printf("%d\n", nextPrime(10000));
	return 0;
}
