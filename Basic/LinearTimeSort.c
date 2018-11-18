#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void randomFill(char* a, int size){
	for (int i = 0; i < size; ++i)
		a[i] = (int) rand() % 26 + 'a';
}

void printArray(char** a, int size){
	for (int i = 0; i < size; ++i)
	{
		printf("%s\t", a[i]);
	}
	printf("\n");
}

char** randomStringArray(int size, int length){
	char** res = (char**)malloc(size * sizeof(char*));
	for (int i = 0; i < size; ++i)
	{
		res[i] = (char*)malloc(sizeof(char*) * length);
		randomFill(res[i], length);
	}
	return res;
}

void swap(char* a, char* b){
	char tmp = *a;
	*a = *b;
	*b = tmp;
}
void fillInto(char* a, char* b){
	// while(*a != '\0')
	// 	*a++ = *b++; 
	for(int i = 0; i < strlen(a); i++)
		a[i] = b[i];
}
void countingRadixSort(char** arr, int size){
	int BUCKECTS = 26;
	int length = strlen(arr[0]);

	char** buffer = (char**)malloc(sizeof(char*) * size); 
	for (int i = 0; i < size; ++i)
		buffer[i] = (char*)calloc(length, sizeof(char));

	for (int pos = length - 1; pos >= 0; --pos)
	{
		int count[BUCKECTS + 1] = {0};

		for (int i = 0; i < size; ++i)
			count[arr[i][pos] + 1]++;

		for (int i = 1; i <= BUCKECTS; ++i)
			count[i] += count[i-1];

		

		for (int i = 0; i < size; ++i)
			fillInto(buffer[count[arr[i][pos]] ++], arr[i]);

		printf("ok\n");

		for (int i = 0; i < size; ++i)
			fillInto(arr[i], buffer[i]);

		printf("pos: %d\t\n", pos);
		printArray(arr, size);
	}
}

int main(){

	int size = 10;
	int length = 3;


	char** arr = randomStringArray(size, length);
	printf("Original:\n");
	printArray(arr, size);

	countingRadixSort(arr, size);
	printf("countingRadixSort:\n");
	printArray(arr, size);
}