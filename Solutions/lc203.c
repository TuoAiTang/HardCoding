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
		//Q1
		if(!p)
			return NULL;
		//Q2
		p->val = i;
		p->next = head;
		head = p;
	}
	return head;
}

struct ListNode* createList(int n){
	struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* tail = head;
	for (int i = 0; i < n; ++i)
	{
		struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));
		if(!p)
			return NULL;
		p->val = i;
		p->next = NULL;
		tail->next = p;
		tail = p;
	}
	return head->next;
}

struct ListNode* removeElements(struct ListNode* head, int val) {
	struct ListNode ** p = &head, * tmp;
	while(*p){
		if((*p)->val == val){
			tmp = *p;
			*p = (*p)->next;
			free(tmp);
		}
		else
			p = &((*p)->next);
	}
	return head;   
}

struct ListNode* removeElements_2(struct ListNode* head, int val) {
	struct ListNode* cur = head, *pre = NULL, *tmp;
	while(cur != NULL){
		if(cur->val == val){			
			if(pre != NULL)
				pre->next = cur->next;			
			else
				head = head->next;	
			tmp = cur;						
			cur = cur->next;
			free(tmp);	
		} else{
			pre = cur;
			cur = cur->next;
		}		
	}	
	return head;   
}


int main(){

	struct ListNode* head = createList(5);

	struct ListNode* p = head;

	while(p != NULL){
		printf("%d\n", p->val);
		p = p->next;
	}


	// int a;
	// scanf("%d", &a);

	printf("after removeElements_2:\n");

	p = removeElements_2(head, 2);

	while(p != NULL){
		printf("%d\n", p->val);
		p = p->next;
	}
	

	return 0;
}