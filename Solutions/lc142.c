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
        p->val = i + 1;
        p->next = head;
        tail = tail?tail:p;
        head = p;
    }
    tail->next = head;
    return head;
}

struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            slow = head;
            while(fast && slow != fast){
                fast = fast->next;
                slow = slow->next;
            }
            return slow;   
        }
    }
    return NULL;
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

    // printLL(head);

    struct ListNode* p = detectCycle(head);

    printLL(p);

    return 0;
}
