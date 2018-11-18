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


bool hasPathSum(struct TreeNode* root, int sum) {
    if(root == NULL) return false;
    if(root->left == NULL && root->right == NULL && root->val == sum)
    	return true;
    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root-val);
}