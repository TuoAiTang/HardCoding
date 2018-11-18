#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int getLength(struct ListNode* l){
	struct ListNode* p = l;
	int len = 0;
	while(p){
		len ++;
		p = p->next;
	}
	return len;
}

struct ListNode* getNextRoot(struct ListNode* root, int step){
	struct ListNode* p = root;
	if(!p)
		return NULL;
	for (int i = 0; i < step - 1; ++i)
		p = p?p->next:p;
	if (!p)
		return NULL;
	struct ListNode* tmp = p->next;
	p->next = NULL;
	return tmp;
}

struct ListNode** splitListToParts(struct ListNode* root, int k, int* returnSize) {
	int len = getLength(root);
	int size = len / k;
	int extra = len % k;
	int step = 0;
	struct ListNode **res = (struct ListNode **)malloc(k * sizeof(struct ListNode*));
	struct ListNode* tmp;
	for (int i = 0; i < k; ++i)
	{
		if(extra){
			step = size + 1;
			extra --;
		}
		else{
			step = size;
		}
		res[i] = root;
		if(root){
			for (int i = 0; i < step - 1; ++i)
				root = root->next;
			tmp = root->next;
			root->next = NULL;
			root = tmp;
		}
	}
	
	*returnSize = k;
	return res;
}


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
	int k = 5;
	int a;
	struct ListNode** parts = splitListToParts(head, k, &a);
	printf("List:\n");
	for (int i = 0; i < k; ++i)
	{
		printf("***----%d----***\n", i + 1);
		printLL(parts[i]);
	}

	return 0;

}
