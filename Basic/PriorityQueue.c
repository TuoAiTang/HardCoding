#include<stdio.h>
#include<stdlib.h>


#define MIN_DATA INT_MIN;
typedef int ElementType;

struct HeapStruct{
	int capacity;
	int size;
	ElementType* elements;
};

typedef struct HeapStruct* PriorityQueue;

PriorityQueue initPQ(int initCapacity);
void destroy(PriorityQueue pq);
void makeEmpty(PriorityQueue pq);	//TODO
void insert(PriorityQueue pq, ElementType elem);
ElementType deleteMin(PriorityQueue pq);
ElementType findMin(PriorityQueue pq);
int isEmpty(PriorityQueue pq);
int isFull(PriorityQueue pq);
void remove(PriorityQueue pq, ElementType elem);	//TODO

PriorityQueue initPQ(int initCapacity){
	PriorityQueue pq = (PriorityQueue)malloc(sizeof(struct HeapStruct));
	pq->capacity = initCapacity;
	pq->size = 0;
	//elements[0] stores the dummy root with special MIN_DATA
	//to make insert more easily
	pq->elements = (ElementType*)malloc((initCapacity + 1) * sizeof(ElementType));
	pq->elements[0] = MIN_DATA;
	printf("Success: init a heap with initCapacity : %d\n", pq->capacity);
	return pq;
}

void destroy(PriorityQueue pq){
	pq->capacity = 0;
	pq->size = 0;
	free(pq->elements);
	free(pq);
	printf("Success: destroy the heap!\n");
}

void insert(PriorityQueue pq, ElementType elem){
	if(isFull(pq)){
		printf("Error: insert to a full heap!\n");
		return;
	}
	pq->size++;
	//siftUp
	int i = pq->size;
	while(pq->elements[i / 2] > elem){
		pq->elements[i] = pq->elements[i / 2];
		i /= 2;
	}		
	pq->elements[i] = elem;
	printf("Success: insert an element: %d\n", elem);
}

ElementType deleteMin(PriorityQueue pq){
	if(isEmpty(pq)){
		printf("Error: deleteMin of an empty heap!\n");
		return pq->elements[0];
	}
	ElementType min = pq->elements[1];
	ElementType last = pq->elements[pq->size];

	pq->size--;
	//siftDown
	int i = 1, child;
	//to the bottom layer, has no child
	while(i * 2 <= pq->size){
		child = i * 2;
		//right child check
		if(child != pq->size && pq->elements[child + 1] < pq->elements[child])
			child++;
		if(last > pq->elements[child])
			pq->elements[i] = pq->elements[child];
		else
			break;
		i = child;
	}
	pq->elements[i] = last;
	printf("Success: delete the min element: %d\n", min);
	return min;
}

ElementType findMin(PriorityQueue pq){
	if(isEmpty(pq)){
		printf("Error: deleteMin of an empty heap!\n");
		return pq->elements[0];
	}
	printf("Success: find the min element: %d\n", pq->elements[1]);
	return pq->elements[1];
}

int isFull(PriorityQueue pq){
	return pq->size == pq->capacity;
}

int isEmpty(PriorityQueue pq){
	return pq->size == 0;
}

void buildHeap(PriorityQueue pq, int* array, int arraySize){
	for (int i = 0; i < arraySize; ++i)
	{
		insert(pq, array[i]);
	}
}


int main(){
	PriorityQueue pq = initPQ(3);
	int a[5] = {5,3,4,1,2};
	buildHeap(pq, a, 5);
	findMin(pq);
	deleteMin(pq);
	findMin(pq);

	for (int i = 0; i < 6; ++i)
	{
		deleteMin(pq);
	}

	destroy(pq);
	return 0;
}