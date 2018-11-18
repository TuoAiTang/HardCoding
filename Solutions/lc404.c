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

int sumOfLeftLeaves(struct TreeNode* root) {
    if(root == NULL)
    	return 0;
    int sum = 0;
    struct TreeNode** stack = (struct TreeNode**)malloc(100 * sizeof(struct TreeNode*));
	int top = -1;
	struct TreeNode* p = root;
	stack[++top] = p;
	while(top != -1){
		p = stack[top];
		if(p->left || p->right){

		}
	}

}

int sumOfLeftLeaves(struct TreeNode* root) {
	return helper(root, 0);
}

int helper(struct TreeNode* root, bool isLeft){
	if(root == NULL)
		return 0;
	int sum = 0;
	sum += (isLeft && !root->left && !root->right) ? root->val : 0;
	sum += helper(root->left, 1) + helper(root->right, 0);
	return sum;
}