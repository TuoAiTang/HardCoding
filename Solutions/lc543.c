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

int depthHelper(struct TreeNode* root, int* path){
	if(root == NULL)
    	return 0;
    int left = depthHelper(root->left);
    int right = depthHelper(root->right);
    *path = max(*path, left + right + 1);
    return max(left, right) + 1;
}
int diameterOfBinaryTree(struct TreeNode* root){
	int path = 0;
	depthHelper(root, &path);
	return path;   
}
