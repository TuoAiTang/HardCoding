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

struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    if(!head || !head->next || m == n)
        return head;
    struct ListNode* pre = NULL;
    for(int i = 0; i < m - 1; i ++)
        pre = pre?pre->next:head;
    int len = n - m + 1;
    struct ListNode* khead = NULL, *ktail = NULL, *tmp = NULL;
    struct ListNode* p = NULL;
    for(p = pre?pre->next:head; len > 0; len --){
        tmp = p->next;
        p->next = khead;
        khead = p;
        ktail = ktail?ktail:p;
        p = tmp;
    }
    ktail->next = p;
    if(!pre)
        return khead;

    pre->next = khead;
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
    struct ListNode* head = createList(10);

    printLL(head);

    struct ListNode* p = reverseBetween(head, 1, 10);

    printLL(p);

    return 0;
}
