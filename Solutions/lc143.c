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
        p->val = n - i;
        p->next = head;
        head = p;
    }
    return head;
}

void reorderList(struct ListNode* head) {
    struct ListNode* fast = head, *slow = head;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    struct ListNode* mid = slow, *righth = NULL, *tmp = NULL;
    if(!slow)
        return;
    tmp = slow->next;
    while((slow = tmp)){
        tmp = slow->next;
        slow->next = righth;
        righth = slow;
    }
    struct ListNode* pre = head, *tmp1, *tmp2;
    while(pre != mid && righth){
        tmp1 = pre->next;
        pre->next = righth;

        tmp2 = righth->next;
        righth->next = tmp1;

        righth = tmp2;
        pre = tmp1;
    }
    if(mid)
        mid->next = NULL;
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
    struct ListNode* head = createList(5);

    printLL(head);

    head = NULL;
    reorderList(head);

    printLL(head);

    return 0;
}
