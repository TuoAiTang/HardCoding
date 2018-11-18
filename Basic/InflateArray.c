#include <stdio.h>
#include <stdlib.h>

typedef struct Array{
	int * array;
	int size;
}Array;

Array arrary_create(int init_size){
	Array a;
	a.size = init_size;
	a.array = (int*)malloc(init_size * sizeof(int));
	return a;
}

// Array* array_create(int init_size){
// 	Array a;
// 	a.size = init_size;
// 	a.array = (int*)malloc(init_size * sizeof(int));
// 	return &a;
// }

// Array* array_create(Array* a, int init_size){
// 	a->size = init_size;
// 	a->array = (int*)malloc(init_size * sizeof(int));
// 	return a;
// }
void array_free(Array* a){
	free(a->array);
	a->array = NULL;
	a->size = 0;
}

// void array_inflate(Array* a, int more_size){
// 	int* p = (int*)malloc((a->size + more_size) * sizeof(int));
// 	for (int i = 0; i < a->size; ++i)
// 		p[i] = a->array[i];
// 	free(a->array);
// 	a->array = p;
// 	a->size = a->size + more_size;
// }
void array_inflate(Array* a, int more_size){
	a->array = (int*)realloc(a->array, (a->size + more_size) * sizeof(int));
	a->size = a->size + more_size;
}
int array_at(Array const * a, int index){
	return a->array[index];
}

int main(){

	Array a = arrary_create(10);
	printf("%d\n", a.size);
	array_inflate(&a, 5);	
	printf("%d\n", a.size);
	for (int i = 0; i < a.size; ++i)
	{
		printf("%d\n", array_at(&a, 1));
	}
	array_free(&a);
	printf("ok\n");
	return 0;
}
