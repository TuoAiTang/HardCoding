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
        p->val = i / 3;
        p->next = head;
        head = p;
    }
    return head;
}
//0 ms
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(!head || !head->next)
        return head;
    struct ListNode* fakeNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    fakeNode->next = head;
    struct ListNode* pre = fakeNode, *tmp;
    while(head){
        while(head->next && head->val == head->next->val){
            tmp = head;
            head = head->next;
            free(tmp);
        }
        if(pre->next == head){
            pre = pre->next;
            head = head->next;
        }else{
            pre->next = head->next;
            free(head);
            head = pre->next;
        }
    }
    return fakeNode->next;    
}
//4 ms
struct ListNode* deleteDuplicates_2(struct ListNode* head) {
    if(!head || !head->next)
        return head;
    struct ListNode* fakeNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    fakeNode->next = head;
    struct ListNode* pre = fakeNode;
    while(head){
        if(head->next && head->val == head->next->val){
            int val = head->val;
            while(head && head->val == val){
                pre->next = head->next;
                free(head);
                head = pre->next;
            }
        }
        else{
            pre = head;
            head = head->next;
        }
    }
    return fakeNode->next;    
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
    struct ListNode* head = createList(9);

    printLL(head);

    struct ListNode* p = deleteDuplicates(head);

    printLL(p);

    return 0;
}
