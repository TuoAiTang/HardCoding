/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* middleNode(struct ListNode* head) {
	struct ListNode* p = head;
	int len = 0;
	while(p != NULL){
		p = p->next;
		len++;
	}
	printf("len:%d\n", len);
	int middle = len / 2;
	p = head;
	for(int i = 0; i < middle; i++)
		p = p->next;
    return p;
}

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


int main(){

	struct ListNode* head = createList(1);
	printf("middleNode val:%d\n", middleNode(head)->val);

	struct ListNode* p = head;

	while(p != NULL){
		printf("%d\n", p->val);
		p = p->next;
	}
	

	return 0;
}