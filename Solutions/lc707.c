#include <stdio.h>
#include <stdlib.h>

typedef struct MyLinkedList{
	int val;
	struct MyLinkedList* next;   
} MyLinkedList;

/** Initialize your data structure here. */
MyLinkedList* myLinkedListCreate() {
    MyLinkedList* p = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    p->val = -1;
    p->next = NULL;
    return p;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
	if(index < 0)
		return -1;
	if(!obj->next)
		return -1;
	MyLinkedList* p = obj->next;
    for (int i = 0; i < index; ++i)
    {
    	p = p->next;
    	if(!p)
    		return -1;
    }
    return p->val;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the newp node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
	MyLinkedList* p = (MyLinkedList*)malloc(sizeof(MyLinkedList));
	if(!p)
		return;
	p->val = val;
	p->next = obj->next;
	obj->next = p;   
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList* p = obj;
    while(p->next){
    	p = p->next;
    }
    MyLinkedList* newp = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    if(!newp)
		return;
    newp->val = val;
    newp->next = NULL;
    p->next = newp;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
	if(index < 0)
		return;
	MyLinkedList* p = obj;
    for (int i = 0; i < index; ++i)
    {
    	p = p->next;
    	if(!p)
    		return;
    }
    MyLinkedList* newp = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    if(!newp)
		return;
    newp->val = val;
    newp->next = p->next;
    p->next = newp;
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0)
    	return;
    MyLinkedList* tmp, *p = obj;
    if(!obj->next)
    	return;
    for (int i = 0; i < index; ++i)
    {
    	//ensure the delete node is not null
    	if(!p->next->next)
    		return;
    	p = p->next;
    }
    //p is before the node tobe deletes 
    //normal
    tmp = p->next;
    p->next = p->next->next;
    free(tmp);

}

void myLinkedListFree(MyLinkedList* obj) {
	MyLinkedList* tmp;
	while(obj){
		tmp = obj;
		obj = obj->next;
		free(tmp);
	}   
}

void myLinkedListPrint(MyLinkedList* obj){
	MyLinkedList* p = obj->next;
	while(p){
		printf("%d->", p->val);
		p = p->next;
	}
	printf("NULL\n");
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * struct MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 * myLinkedListAddAtHead(obj, val);
 * myLinkedListAddAtTail(obj, val);
 * myLinkedListAddAtIndex(obj, index, val);
 * myLinkedListDeleteAtIndex(obj, index);
 * myLinkedListFree(obj);
 */

int main(){

	MyLinkedList* obj = myLinkedListCreate();
	
	myLinkedListAddAtHead(obj, 1);
	myLinkedListPrint(obj);
	myLinkedListAddAtTail(obj, 3);
	myLinkedListAddAtIndex(obj, 0, 2);	
	myLinkedListPrint(obj);

	int param_1 = myLinkedListGet(obj, 1);
	printf("param_1:%d\n", param_1);

	myLinkedListDeleteAtIndex(obj, 1);
	printf("after delete:");
	myLinkedListPrint(obj);

	myLinkedListFree(obj);	

	return 0;
}
