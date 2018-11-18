#include <stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* createList(int n){
	struct ListNode* head = NULL;
	struct ListNode* tail = NULL;
	for (int i = 0; i < n; ++i)
	{
		struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));
		//check allocate status
		if(p == NULL){
			return NULL;
		}
		if(tail == NULL){
			tail = p;
		}
		p->val = i / 3;
		p->next = head;
		head = p;
	}
	//build cycle
	tail->next = head->next;
	return head;
}

bool hasCycle(struct ListNode *head) {

	struct ListNode* fast = head;
	struct ListNode* slow = head;
	while(fast != NULL && fast->next != NULL){
		fast = fast->next->next;
		slow = slow->next;
		if(fast == slow)
			return true;
	}
    return false;
}

int main(){

	struct ListNode* head = createList(8);

	struct ListNode* p = head;

	// while(p != NULL){
	// 	printf("%d\n", p->val);
	// 	p = p->next;
	// }



	printf("hasCycle?%d\n", hasCycle(head));



	return 0;
}