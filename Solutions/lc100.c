#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct TreeNode{
	ElementType val;
	struct TreeNode* left;
	struct TreeNode* right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q){
	if(!p && !q)
		return 1;
	else if((!p && q) || (p && !q))
		return 0;
	if(p->val != q->val)
		return 0;
	if(!isSameTree(p->left, q->left) || !isSameTree(p->right, q->right))
		return 0;

	return 1;
}

int main(){

	

	return 0;
}