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

int Min(int a, int b){
	return a < b ? a : b;
}
int dfs(struct TreeNode* root, int min){
	if(root == NULL)
		return -1;
	if(root->val > min) 
		return root->val;
	int smL = dfs(root->left, min);
	int smR = dfs(root->right, min);
	if(smL == -1)
		return smR;
	if(smR == -1)
		return smL;
	return Min(smL, smR);
}
int bfs(struct TreeNode* root){
	if(root == NULL)
		return -1;
	struct TreeNode** stack = (struct TreeNode**)malloc(100 * sizeof(struct TreeNode*));
	int top = -1;
	stack[++top] = root;
	int sm = INT_MAX;
	bool found = false;
	while(top != -1){
		struct TreeNode* p = stack[top--];
		if(p->val > root->val){
			sm = Min(sm, p->val);
			found = true;
			continue;
		}
		if(p->right)
			stack[++top] = p->right;
		if(p->left)
			stack[++top] = p->left;
	}
	return found ? sm : -1;
}
int findSecondMinimumValue(struct TreeNode* root) {
    if(root == NULL)
    	return -1;
    //return dfs(root, root->val);
    return bfs(root);
}


