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

typedef struct ListNode Node;

struct ListNode* insertionSortList(struct ListNode* head) {
	if(!head || !head->next) return head;
	Node* dummy = (Node*)malloc(sizeof(Node));
	dummy->next = head;
    Node *cur = head, *tmp, *pre;
    while(cur && cur->next){
        if(cur->val <= cur->next->val)
            cur = cur->next;
        else{
            tmp = cur->next;
            pre = dummy;
            cur->next = cur->next->next;
            while(pre->next->val <= tmp->val)
                pre = pre->next;
            tmp->next = pre->next;
            pre->next = tmp;
        }
    }
    return dummy->next;
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

	Node* head = createList(10);
	head = insertionSortList(head);
	printLL(head);
	return 0;
}
