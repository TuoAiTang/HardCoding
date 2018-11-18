#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include "Sort.c"
void randomFillByLength(int* array, int size){
	srand(46);
	
	for (int i = 0; i < size; ++i){
		int a = (int) rand() % 10 + 1;
		a = (a == 10) ? 1 : a;
		int b = (int) rand() % 10 + 1;
		b = (b == 10) ? 1 : b;
		int c = (int) rand() % 10 + 1;
		c = (c == 10) ? 1 : c;
		array[i] = a * 100 + b * 10 + c;
	}
}


//a, the array; 
//size, the size of array a;
//len, the length of number in array a
void radixSort(int* a, int size, int len){
	int radix = 10;

	//Least Significant Digit
	int* out = (int*)malloc(size * sizeof(int));
	for (int pos = 0; pos < len; ++pos)
	{
		int count[radix + 1] = {0};
		int divide = (int)pow(radix, pos);

		for (int i = 0; i < size; ++i)
			count[a[i] / divide % radix + 1]++;

		for(int i = 1; i <= radix; i++)
			count[i] += count[i - 1];

		for (int i = 0; i < size; ++i)
			out[count[a[i] / divide % radix] ++] = a[i];

		for (int i = 0; i < size; ++i)	
			a[i] = out[i];
	}
	free(out);
}



int main(){

	int size = 1e5;

	clock_t start, end;

	int* a = (int*)malloc(sizeof(int) * size);

	start = clock();
	randomFillByLength(a, size);
	end = clock();
	printf("FillCost: %f seconds\n", (double)(end-start) / CLOCKS_PER_SEC);
	// printArray(a, size);


	start = clock();
	// radixSort(a, size, 3);
	// BubbleSort(a, size);
	// InsertSort(a, size);
	// ShellSort(a, size);
	// HeapSort(a, size);
	end = clock();
	printf("SortCost: %f seconds\n", (double)(end-start) / CLOCKS_PER_SEC);
	// printArray(a, size);

}