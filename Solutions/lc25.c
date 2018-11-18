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

struct ListNode* reverseKGroup(struct ListNode* head, int k) 
{
	int length = 0; 
	struct ListNode* p = head;
	while(p){
		p = p->next;
		length += 1;
	}	
	if(length < k)
		return head;
	int res_node = length;
	struct ListNode* head2 = (struct ListNode*)malloc(sizeof(struct ListNode)); 
	struct ListNode* dummyHead = head2;
	struct ListNode* kHead = NULL, *tmp, *first = NULL;
	while(res_node >= k){
		int n = k;
		kHead = NULL;
		first = NULL;
		while(n--){
			first = first?first:head;
			tmp = head->next;
			head->next = kHead;
			kHead = head;
			head = tmp;
		}
		dummyHead->next = kHead;
		dummyHead = first;
		res_node -= k;
	}
	dummyHead->next = head;
	return head2->next;
}

int main(){

	struct ListNode* l1, *p;

	l1 = createList(1);

	printLL(l1);

	p = reverseKGroup(l1, 4);

	printLL(p);

	return 0;
}