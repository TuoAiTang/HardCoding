#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* createListByTail(int n){
	struct ListNode *head = NULL, *tail = NULL, *p;
	for(int i = 0; i < n; i++){
		p = (struct ListNode*)malloc(sizeof(struct ListNode));
		p->val = i;
		p->next = NULL;
		if(i == 0){
			head = p;
			tail = p;
		}else{
			tail->next = p;
			tail = p;
		}	
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

int main(){

	struct ListNode* p = createListByTail(10);
	printLL(p);

	return 0;
}
