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

struct ListNode* swapPairs(struct ListNode* head) {
    if(!head || !head->next)
        return head;
    struct ListNode* cur = head;
    struct ListNode* first = NULL;
    struct ListNode* prev = NULL;

    while(cur && cur->next){
        first = cur->next;
        cur->next = first->next;
        first->next = cur;
        if(!prev)
            head = first;
        else
            prev->next = first;
        prev = cur;
        cur = cur->next;
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

int main(){
    struct ListNode* head = createList(3);

    printLL(head);

    struct ListNode* p = swapPairs(head);

    printLL(p);

    return 0;
}