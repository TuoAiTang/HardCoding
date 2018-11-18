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
		p->val = i + 1;
		p->next = head;
		head = p;
	}
	return head;
}

struct ListNode* oddEvenList(struct ListNode* head) {
    if(!head || !head->next || !head->next->next)
    	return head;
    struct ListNode* tmp1 = head, *tmp2 = head->next, *evenHead = tmp2;
    while(tmp2->next){
    	tmp1->next = tmp1->next->next;
    	tmp2->next = tmp2->next->next;
    	tmp1 = tmp1->next;
    	tmp2 = tmp2->next;
    }
    tmp1->next = evenHead;
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
	struct ListNode* head = createList(8);

	printLL(head);

	struct ListNode* p = oddEvenList(head);

	printLL(p);

	return 0;
}