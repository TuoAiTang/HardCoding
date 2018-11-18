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
		p->val = i / 3;
		p->next = head;
		head = p;
	}
	return head;
}

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* cur = head;
    while(cur != NULL && cur->next != NULL){
        if(cur->val == (cur->next)->val){
            struct ListNode* tmp = cur->next;
            cur->next = cur->next->next;
            free(tmp);
        }else{
        	cur = cur->next;
        }
    }
    return head;
}

int main(){

	struct ListNode* head = createList(8);

	struct ListNode* p = head;


	while(p != NULL){
		printf("%d\n", p->val);
		p = p->next;
	}

	p = deleteDuplicates(head);

	printf("after deleteDuplicates:\n");

	while(p != NULL){
		printf("%d\n", p->val);
		p = p->next;
	}

	p = deleteDuplicates(head);



	return 0;
}