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

struct ListNode* removeNthFromEnd_2(struct ListNode* head, int n) {
    int len = 0;
    struct ListNode* p = head;
    struct ListNode* tmp = NULL;
    while(p){
        p = p->next;
        len ++;
    }
    if(len <= 1) 
        return NULL;
    n = len - n + 1;
    struct ListNode* pre = NULL;
    //push the pre node
    while(--n)
        pre = pre?pre->next:head;
    //not delete the head
    if(pre){
        tmp = pre->next;
        pre->next = tmp->next;
    }
    //delete the head
    else{
        tmp = head;
        head = head->next;
    }
    free(tmp);
    return head;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if(!head)
        return NULL;
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    struct ListNode* tmp = NULL;
    while(n--)
        fast = fast->next;
    if(!fast){
        tmp = head;
        head = head->next;
        free(tmp);
        return head;
    }
    while(fast->next){
        fast = fast->next;
        slow = slow->next;
    }
    tmp = slow->next;
    slow->next = slow->next->next;
    free(tmp);
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

    struct ListNode* p = removeNthFromEnd(head, 1);

    printLL(p);

    return 0;
}
