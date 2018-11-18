#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int max(int a, int b){
	return a > b ? a : b;
}


typedef int ElementType;

struct TreeNode{
	ElementType val;
	struct TreeNode* left;
	struct TreeNode* right;
};

struct TreeNode* invertTree(struct TreeNode* root) {
    if(root == NULL)
    	return root;

    root->left = invertTree(root->left);
    root->right = invertTree(root->right);
    struct TreeNode* tmp = root->right;
    root->right = root->left;
    root->left = tmp;
    return root;
}