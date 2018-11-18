#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* array;
    int front;
    int rear;
    int cnt;
    int size;
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k){
	MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	obj->array = (int*)malloc((k + 1) * sizeof(int));
	obj->front = 0;
	obj->rear = 1;
	obj->cnt = 0;
	obj->size = k + 1;
	return obj;
}

int myCircularQueueIsFull(MyCircularQueue* obj){
	return obj->cnt == obj->size - 1;
}

int myCircularQueueIsEmpty(MyCircularQueue* obj){
	return obj->cnt == 0;
}

int myCircularQueueEnQueue(MyCircularQueue* obj, int val){
	if(myCircularQueueIsFull(obj))
		return 0;
	obj->array[obj->rear] = val;
	obj->rear = (obj->rear + 1) % obj->size;
	obj->cnt++;
	return 1;
}

int myCircularQueueDeQueue(MyCircularQueue* obj){
	if(myCircularQueueIsEmpty(obj))
		return 0;
	obj->front = (obj->front + 1) % obj->size;
	obj->cnt--;
	return 1;
}

int myCircularQueueFront(MyCircularQueue* obj){
	if(myCircularQueueIsEmpty(obj))
		return -1;
	int index = (obj->front + 1) % obj->size;
	return obj->array[index];
}

int myCircularQueueRear(MyCircularQueue* obj){
	if(myCircularQueueIsEmpty(obj))
		return -1;
	int index = (obj->rear - 1 + obj->size) % obj->size;
	return obj->array[index];
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->array);
    free(obj);
}


int main(){



	return 0;
}