#include <stdio.h>
#include <stdlib.h>
// start 16.01
//end 20.00
typedef struct {
    int* array;
    int front;
    int rear;
    int size;
} MyCircularDeque;

/** Checks whether the circular deque is empty or not. */
int myCircularDequeIsEmpty(MyCircularDeque* obj) {
    return ((obj->front + 1) % obj->size == obj->rear) ? 1 : 0 ;
}

/** Checks whether the circular deque is full or not. */
int myCircularDequeIsFull(MyCircularDeque* obj) {
    return obj->front == obj->rear ? 1 : 0;
}

/** Initialize your data structure here. Set the size of the deque to be k. */
MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* mq = (MyCircularDeque*)malloc(sizeof(MyCircularDeque));
    //if k = 1, malloc k * sizeof int, the queue is full already
    mq->array = (int*)malloc((k + 1) * sizeof(int));
    mq->front = k;
    mq->rear = 0;
    mq->size = k + 1;
    return mq;
}

/** Adds an item at the front of Deque. Return true if the operation is successful. */
int myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if(myCircularDequeIsFull(obj))
    	return 0;

    obj->array[obj->front] = value;
    obj->front = (obj->front - 1 + obj->size) % obj->size;   
    return 1;
}

/** Adds an item at the rear of Deque. Return true if the operation is successful. */
int myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if(myCircularDequeIsFull(obj))
    	return 0;
    obj->array[obj->rear] = value;
    obj->rear = (obj->rear + 1) % obj->size;  
    return 1;
}

/** Deletes an item from the front of Deque. Return true if the operation is successful. */
int myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if(myCircularDequeIsEmpty(obj))
    	return 0;
    obj->front = (obj->front + 1) % obj->size;
    return 1;
}

/** Deletes an item from the rear of Deque. Return true if the operation is successful. */
int myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if(myCircularDequeIsEmpty(obj))
    	return 0;
    obj->rear = (obj->rear - 1 + obj->size) % obj->size;
    return 1;
}

/** Get the front item from the deque. */
int myCircularDequeGetFront(MyCircularDeque* obj) {
	int index = (obj->front + 1) % obj->size;
    return myCircularDequeIsEmpty(obj) ? -1 : obj->array[index];
}

/** Get the last item from the deque. */
int myCircularDequeGetRear(MyCircularDeque* obj) {
	int index = (obj->rear - 1 + obj->size) % obj->size;
    return myCircularDequeIsEmpty(obj) ? -1 : obj->array[index];
}

void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj->array);
    free(obj);
}


int main(){

	MyCircularDeque* mq = myCircularDequeCreate(3);
	printf("is empty:%d\n", myCircularDequeIsEmpty(mq));
	myCircularDequeInsertFront(mq, 1);
	myCircularDequeInsertFront(mq, 2);
	printf("front:%d\n", myCircularDequeGetFront(mq));
	printf("rear:%d\n", myCircularDequeGetRear(mq));
	myCircularDequeDeleteFront(mq);
	myCircularDequeInsertLast(mq, 3);
	myCircularDequeDeleteFront(mq);
	printf("front:%d\n", myCircularDequeGetFront(mq));

	// printf("is empty:%d\n", myCircularDequeIsEmpty(mq));
	// printf("front: %d\n", myCircularDequeGetFront(mq));
	// myCircularDequeInsertLast(mq, 3);
	// printf("front:%d\n", myCircularDequeGetFront(mq));
	// printf("rear:%d\n", myCircularDequeGetRear(mq));
	// myCircularDequeInsertFront(mq, 4);
	// printf("front:%d\n", myCircularDequeGetFront(mq));
	// printf("is full:%d\n", myCircularDequeIsFull(mq));
	// myCircularDequeInsertFront(mq, 6);
	// printf("is full:%d\n", myCircularDequeIsFull(mq));
	// printf("front:%d\n", myCircularDequeGetFront(mq));
	// printf("rear:%d\n", myCircularDequeGetRear(mq));



	return 0;
}
