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
		p->val = i;
		p->next = head;
		head = p;
	}
	return head;
}

void middleList(struct ListNode* head, struct ListNode** mid){
	struct ListNode *fast = head, *slow = head;
	while(fast && fast->next){
		fast = fast->next->next;
		slow = slow->next;
	}
	*mid = slow;
}

void ReverseList(struct ListNode* head, struct ListNode** reverse){
	struct ListNode *p = head, *newH = NULL, *tmp;
	while(p){
		tmp = p->next;
		p->next = newH;
		newH = p;
		p = tmp;
	}
	*reverse = newH;
}

bool isPalindrome(struct ListNode* head) {
	if(head == NULL)
		return true;
	struct ListNode *mid, *reverseH;
	middleList(head, &mid);
	ReverseList(head, &reverseH);
	while(head){
		if(reverseH->val != head->val)
			return false;
		reverseH = reverseH->next;
		head = head->next;
	}
	return true;
}

struct ListNode* reverseList(struct ListNode* head){
	struct ListNode* newH = NULL;
	struct ListNode* p = head;
	while(p){
		struct ListNode* newP = (struct ListNode*)malloc(sizeof(struct ListNode));
		if(!newP)
			return NULL;
		newP->val = p->val;
		newP->next = newH;
		newH = newP;
		p = p->next;
	}
	return newH;
}


bool isPalindrome_2(struct ListNode* head) {
	if(head == NULL)
		return false;
	struct ListNode* newH = reverseList(head);
	struct ListNode* p = head, *q = newH;
	while(p){
		if(p->val != q->val)
			return false;
		p = p->next;
		q = q->next;
	}
	return true;    
}


int main(){

	struct ListNode* head = createList(4);

	struct ListNode* p;

	ReverseList(head, &p);
	p = head;
	// middleList(head, &p);

	while(p){
		printf("%d\n", p->val);
		p = p->next;
	}


	printf("isPalindrome?:%d\n", isPalindrome(head));	
	return 0;
}