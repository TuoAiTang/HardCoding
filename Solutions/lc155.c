#include <stdio.h>
#include <stdlib.h>

// typedef struct node{
// 	int val;
//     struct node* next;
// } node;

// typedef struct{
// 	node* head;
// 	node* minhead;
// } MinStack;

// /** initialize your data structure here. */
// MinStack* minStackCreate(int maxSize) {
//     node* head = (node*)malloc(sizeof(node));
//     head->next = NULL;
//     node* minhead = (node*)malloc(sizeof(node));
//     minhead->next = NULL;
//     MinStack* stack = (MinStack*)malloc(sizeof(MinStack));
//     stack->head = head;
//     stack->minhead = minhead;
//     return stack;
// }

// void minStackPush(MinStack* obj, int x) {
//     node* top = (node*)malloc(sizeof(node));
//     top->val = x;
//     top->next = obj->head->next;
//     obj->head->next = top;

//     if(!obj->minhead->next || obj->minhead->next->val >= x){
//     	node* mintop = (node*)malloc(sizeof(node));
//     	mintop->val = x;
//     	mintop->next = obj->minhead->next;
//     	obj->minhead->next = mintop;
//     }
// }

// void minStackPop(MinStack* obj) {
//    	node* head = obj->head;
//    	node* minhead = obj->minhead;
//    	node* tmp;

//    	tmp = head->next;
//    	int val = tmp->val;
//    	head->next = tmp->next;
//    	free(tmp);

//    	if(minhead->next->val == val){
//    		tmp = minhead->next;
//    		minhead->next = tmp->next;
//    		free(tmp);
//    	}

// }

// int minStackTop(MinStack* obj) {
//     return obj->head->next->val;
// }

// int minStackGetMin(MinStack* obj) {
//     return obj->minhead->next->val;
// }

// void minStackFree(MinStack* obj) {
//     node* head = obj->head;
//     node* minhead = obj->minhead;
//     node* tmp;
//     while(head){
//     	tmp = head;
//     	head = head->next;
//     	free(tmp);
//     }
//     while(minhead){
//     	tmp = minhead;
//     	minhead = minhead->next;
//     	free(tmp);
//     }
// }

typedef struct stack{
	int val;
    struct stack* next;
    int min;
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize) {
    MinStack* stack = (MinStack*)malloc(sizeof(MinStack));
    stack->next = NULL;
    stack->val = INT_MAX;  //stack val restore the min number
    return stack;
}

void minStackPush(MinStack* obj, int x) {
    MinStack* top = (MinStack*)malloc(sizeof(MinStack));
    top->val = x;
    top->next = obj->next;
    obj->next = top;
    obj->val = x < obj->val? x: obj->val;
}

void minStackPop(MinStack* obj) {
    MinStack* tmp = obj->next;
    obj->next = obj->next->next;
    free(tmp);
    if(x == obj->val)
    {
    	obj->val = INT_MAX;
    	tmp = obj->next;
    	while((tmp = tmp->next))
    		obj->val =  tmp->val < obj->val? tmp->val : obj->val;
    }
}

int minStackTop(MinStack* obj) {
    return obj->next->val;
}

int minStackGetMin(MinStack* obj) {
    return obj->val;
}

void minStackFree(MinStack* obj) {
    MinStack* tmp;
    while(obj){
    	tmp = obj;
    	obj = obj->next;
    	free(tmp);
    }
}

int main(){




	return 0;
}