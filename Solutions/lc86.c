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
        p->val = (i + 2) % 5;
        p->next = head;
        head = p;
    }
    return head;
}

struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode* pbh = NULL, *p = head, *prev = NULL, *bigCur;
    //pbh the first node which value >= x
    //p the traverse pointer
    //prev the node before the pbh
    //bigCur the big node curret
    while(p){
        if(p->val >= x){
            pbh = p;
            break;
        }
        prev = p;
        p = p->next;
    }
    if(!pbh)
        return head;
    bigCur = pbh;
    p = p->next;
    while(p){
        if(p->val < x){
            bigCur->next = p->next;
            p->next = pbh;
            if(!prev)
                head = p;
            else
                prev->next = p;
            prev = p;
        }
        else{
            bigCur = p;
        }
        p = bigCur->next;
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
    struct ListNode* head = createList(10);

    printLL(head);

    struct ListNode* p = partition(head, 3);

    printLL(p);

    return 0;
}
