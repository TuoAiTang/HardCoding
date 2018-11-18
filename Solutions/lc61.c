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

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(!head)
        return head;
    struct ListNode* fast = head, *slow = head, *tmp;
    //get length
    int len = 0;
    while(fast){
        fast = fast->next;
        len ++;
    }
    fast = head;
    //simplify k
    //note that 0 % n = 0
    k = k % len;
    if(k == 0)
        return head;
    while(k--)
        fast = fast->next;

    // while fast is not the tail
    while(fast->next){
        fast = fast->next;
        slow = slow->next;
    }
    //fast reaches the tail
    tmp = head;
    head = slow->next;
    fast->next = tmp;
    slow->next = NULL;

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
    struct ListNode* head = createList(5);

    printLL(head);

    struct ListNode* p = rotateRight(head, 5);

    printLL(p);

    int a = 0;
    scanf("%d", a);

    return 0;
}
