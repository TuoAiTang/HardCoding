#include <stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* createList(int n){
	struct ListNode* head = NULL;
	for (int i = 0; i < n; ++i)
	{
		struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));
		p->val = i + 1;
		p->next = head;
		head = p;
	}
	return head;
}

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* tmpHead = NULL;
    struct ListNode* p = head;
    while(p != NULL){
    	struct ListNode* tmp = p->next;
    	p->next = tmpHead;
    	tmpHead = p;
    	p = tmp;
    }
    return tmpHead;
}


int main(){

	struct ListNode* head = createList(5);

	struct ListNode* p = head;

	while(p != NULL){
		printf("%d\n", p->val);
		p = p->next;
	}

	printf("reversed:\n");

	p = reverseList(head);

	while(p != NULL){
		printf("%d\n", p->val);
		p = p->next;
	}



	return 0;
}