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
    if(root == p || root = q)
    	return root;
    struct TreeNode left = lowestCommonAncestor(root->left, p, q);
    struct TreeNode right = lowestCommonAncestor(root->right, p, q);

    if(left && right)
    	return root;
    return left ? left : right;
}
