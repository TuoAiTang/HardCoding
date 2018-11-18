#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* createList(int n){
    struct ListNode* head = NULL, *tail = NULL;
    for (int i = 0; i < n; ++i)
    {
        struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));
        p->val = 5 - i;
        p->next = head;
        tail = tail?tail:p;
        head = p;
    }
    return head;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    if(!l1 || !l2)
        return l1?l2:l1;
    int carry = 0;
    int n = 0;
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* tail = head;
    while(l1 || l2){
        struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));
        n = (l1?l1->val:0) + (l2?l2->val:0) + carry;
        p->val = n % 10;
        p->next = NULL;
        carry = n / 10;
        tail->next = p;
        tail = p;
        l1 = l1?l1->next:l1;
        l2 = l2?l2->next:l2;
    }
    if(carry){
        struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));
        p->val = 1;
        p->next = NULL;
        tail->next = p;
    }
    return head->next;
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
    struct ListNode* l1 = createList(5);
    struct ListNode* l2 = createList(5);

    printLL(l1);
    printLL(l2);
    struct ListNode* p = addTwoNumbers(l1, l2);


    printLL(p);

    return 0;
}
