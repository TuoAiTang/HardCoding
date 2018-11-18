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
		p->val = i;
		p->next = head;
		head = p;
	}
	return head;
}


struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	struct ListNode *pa = headA, *pb = headB;
	while(pa && pb){
		if(pa == pb)
			return pa;
		if(pa->next == NULL && pb->next != NULL){
			pa = headB;
			pb = pb->next;
			continue;
		}
		if(pa->next != NULL && pb->next == NULL){
			pb = headA;
			pa = pa->next;
			continue;
		}
		if(pa->next == NULL && pb->next == NULL)
			return NULL;
		pa = pa->next;
		pb = pb->next;		
	}
	return NULL;
}

int main(){

	struct ListNode *headA = createList(1), *headB = (struct ListNode*)malloc(sizeof(struct ListNode));
	headB->val = 4;
	headB->next = headA;

	struct ListNode *p = getIntersectionNode(headB, headA);
	if(!p)
		printf("NULL!\n");

	p = headB;

	while(p){
		printf("%d\n", p->val);
		p = p->next;
	}
	printf("************\n");
	p = headA;

	while(p){
		printf("%d\n", p->val);
		p = p->next;
	}


	return 0;
}