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
		p->val = i + 5;
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

int getLength(struct ListNode* l){
	struct ListNode* p = l;
	int len = 0;
	while(p){
		len ++;
		p = p->next;
	}
	return len;
}

int helper(struct ListNode* l1, struct ListNode* l2, struct ListNode* tail, int pad_len){
	if(!l1 && !l2)
		return 0;
	int carry = 0;
	struct ListNode*p = (struct ListNode*)calloc(1, sizeof(struct ListNode));
	tail->next = p;
	tail = tail->next;
	carry = helper(l1->next, ((pad_len)?l2:l2->next), tail, ((pad_len)?pad_len - 1:0));
	int result = l1->val + ((pad_len)?0:l2->val) + carry;
	p->val = result % 10;
	carry = result / 10;
	return carry;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	if(!l1 || !l2)
		return l1 ? l1 : l2;
	struct ListNode* head, *tail;
	int l1_len = getLength(l1), l2_len = getLength(l2), pad_len = 0;
	pad_len = l1_len > l2_len ? (l1_len - l2_len) : (l2_len - l1_len);
	head = (struct ListNode*)calloc(1, sizeof(struct ListNode));
	tail = head;
	//make sure args1.length > args2.length
	int carry = helper((l1_len>l2_len? l1:l2), (l1_len>l2_len?l2:l1), tail, pad_len);
	if(carry == 0)
		return head->next;
	else{
		head->val = 1;
		return head;
	}	  
}



int main(){
	struct ListNode* l1, *l2, *p;

	l1 = createList(3);
	printf("l1:");
	printLL(l1);

	l2 = createList(2);
	printf("l2:");
	printLL(l2);

	p = addTwoNumbers(l1, l2);
	printf("p:");
	printLL(p);

	return 0;
}
