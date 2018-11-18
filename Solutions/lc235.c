#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int Max(int a, int b){
	return a > b ? a : b;
}
int Min(int a, int b){
	return a < b ? a : b;
}

typedef int ElementType;

struct TreeNode{
	ElementType val;
	struct TreeNode* left;
	struct TreeNode* right;
};

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if(root == NULL)
    	return NULL;
    if(root->val > q->val)
    	return lowestCommonAncestor(root->left, p, q);
    if(root->val < p->val)
    	return lowestCommonAncestor(root->right, p, q);
    //root->val in [p->val, q->val]
    return root;
}
