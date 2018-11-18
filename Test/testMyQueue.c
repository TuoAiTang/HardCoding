#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* array;
    int front;
    int rear;
    int cnt;
    int size;
} MyQueue;

MyQueue* myQueueCreate(int maxSize){
	MyQueue* mq = (MyQueue*)malloc(sizeof(MyQueue));
	mq->array = (int*)malloc((maxSize + 1) * sizeof(int));
	mq->front = 0;
	mq->rear = 1;
	mq->cnt = 0;
	mq->size = maxSize + 1;
	return mq;
}

// int isFull(MyQueue* mq){
// 	return mq->cnt == mq->size - 1;
// }	

// int isEmpty(MyQueue* mq){
// 	return mq->cnt == 0;
// }
int isFull(MyQueue* mq){
	return ((mq->rear + 1)) % mq->size == mq->front;
}	

int isEmpty(MyQueue* mq){
	return ((mq->front + 1) % mq->size) == mq->rear;
}

int enqueue(MyQueue* mq, int val){
	if(isFull(mq))
		return 0;
	mq->array[mq->rear] = val;
	mq->rear = (mq->rear + 1) % mq->size;
	mq->cnt++;
	return 1;
}

int dequeue(MyQueue* mq){
	if(isEmpty(mq))
		return 0;
	mq->front = (mq->front + 1) % mq->size;
	mq->cnt--;
	return 1;
}

int getFront(MyQueue* mq){
	if(isEmpty(mq))
		return -1;
	int index = (mq->front + 1) % mq->size;
	return mq->array[index];
}

int getRear(MyQueue* mq){
	if(isEmpty(mq))
		return -1;
	int index = (mq->rear - 1 + mq->size) % mq->size;
	return mq->array[index];
}

void printQueue(MyQueue* mq){
	int len = (mq->rear - mq->front - 1 + mq->size) % mq->size;
	int start = (mq->front + 1) % mq->size;
	
	printf("\n----detail----\n");
	for (int i = 0; i < len; ++i)
	{
		int index = (start + i) % mq->size;
		printf("%d-", mq->array[index]);
	}
	printf("end\nfront:%d\n", getFront(mq));
	printf("rear:%d\n", getRear(mq));
	printf("cnt:%d\n", mq->cnt);
	printf("size:%d\n", mq->size-1);
	printf("isEmpty:%d\n", isEmpty(mq));
	printf("isFull:%d\n", isFull(mq));
	printf("--------------\n");
}

void freeMyQueue(MyQueue* mq){
	free(mq->array);
	free(mq);
}


int main(){
	int size = 4;
	MyQueue* mq = myQueueCreate(size);
	for (int i = 0; i < 4; ++i)
		enqueue(mq, i + 1);
	printQueue(mq);

	for (int i = 0; i < 3; ++i)
		dequeue(mq);
	printQueue(mq);

	return 0;
}