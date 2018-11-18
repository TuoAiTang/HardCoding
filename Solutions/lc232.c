#include <stdio.h>
#include <stdlib.h>
// start 14.50
//end 15.52

typedef struct {
	//stack s2 is for auxiliary
    int* s1;
    int t1;
    int* s2;
    int t2;
    int front;
} MyQueue;

/** Initialize your data structure here. */
MyQueue* myQueueCreate(int maxSize) {
	MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
	queue->s1 = (int*)malloc(maxSize * sizeof(int));
	queue->s2 = (int*)malloc(maxSize * sizeof(int));
	queue->t1 = -1;
	queue->t2 = -1;
    return queue;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
	//abvious O(1)
	//s1 is empty
    if(obj->t1 == -1)   	
    	obj->front = x;

	obj->s1[++(obj->t1)] = x;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
	//at the worst case,transport all element from s1 to s2
	//amortized, the time complexity is O(1)
    if(obj->t2 == -1)
    	while(obj->t1 != -1)
    		obj->s2[++(obj->t2)] = obj->s1[(obj->t1)--];

	return obj->s2[(obj->t2)--];

}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    if(obj->t2 == -1)
    	return obj->front;
    return obj->s2[obj->t2];
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return (obj->t1 == -1 && obj->t2 == -1) ? 1 : 0;
}

void myQueueFree(MyQueue* obj) {
    free(obj->s1);
    free(obj->s2);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * struct MyQueue* obj = myQueueCreate(maxSize);
 * myQueuePush(obj, x);
 * int param_2 = myQueuePop(obj);
 * int param_3 = myQueuePeek(obj);
 * bool param_4 = myQueueEmpty(obj);
 * myQueueFree(obj);
 */

 int main(){


 	int maxSize = 10;
 	MyQueue* q = myQueueCreate(maxSize);
 	myQueuePush(q, 3);
 	myQueuePush(q, 4);
 	printf("%d\n", myQueuePeek(q));
 	myQueuePop(q);
 	printf("%d\n", myQueuePeek(q));
 	printf("is empty: %d\n", myQueueEmpty(q));
 	myQueuePop(q);
 	printf("is empty: %d\n", myQueueEmpty(q));


 	return 0;
 }