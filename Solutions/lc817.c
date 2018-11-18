#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* createList(int n){
	struct ListNode* head = NULL;
	for (int i = 0; i < n; ++i)
	{
		struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));
		p->val = 2 - i;
		p->next = head;
		head = p;
	}
	return head;
}

void printLL(struct ListNode* obj){
	struct ListNode* p = obj;
	while(p){
		printf("%d->", p->val);
		p = p->next;
	}
	printf("NULL\n");
}

int contains(int val, int* G, int GSize){
	for (int i = 0; i < GSize; ++i)
	{
		if(val == G[i])
			return 1;
	}
	return 0;
}

int numComponents_2(struct ListNode* head, int* G, int GSize) {
	struct ListNode* p = head;
	int count = 0;
	int flag = -1;
	while(p){
		if(contains(p->val, G, GSize)){
			if(flag == -1)
				count ++;
			flag = 1;
		}
		else
			flag = -1;			
		p = p->next;
	}
	return count;		
}
int numComponents(struct ListNode* head, int* G, int GSize) {
	struct ListNode* p = head;
	int a[100000] = {0};
	for (int i = 0; i < GSize; ++i)
		a[G[i]] = 1;
	int count = 0;
	int flag = -1;
	while(p){
		if(a[p->val]){
			if(flag == -1)
				count ++;
			flag = 1;
		}
		else
			flag = -1;			
		p = p->next;
	}
	return count;		
}

void testInit(){
	int a[5];
	for (int i = 0; i < 5; ++i)
	{
		printf("%d\n", a[i]);
	}
}


int main(){

	struct ListNode* p = createList(3);
	printLL(p);
	int G[2] = {0, 2};
	int num = numComponents(p, G, 2);
	printf("numComponents:%d\n", num);
	testInit();
	return 0;
}
