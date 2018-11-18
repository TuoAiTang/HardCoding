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

int maxDepth(struct TreeNode* root) {
    if(root == NULL)
    	return 0;
    int depth = 0;
    depth = max(maxDepth(root->left), maxDepth(root->right)) + 1;
    return depth;
}
