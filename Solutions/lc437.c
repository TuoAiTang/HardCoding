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

// int pathSum(struct TreeNode* root, int sum) {
//     if(root == NULL)
//     	return 0;
//     return dfs(root, sum) + pathSum(root->left, sum) 
//     		+ pathSum(root->right, sum);
// }

// int dfs(struct TreeNode* root, int sum){
// 	if(root == NULL)
// 		return 0;
// 	return ((root->val == sum) ? 1 : 0) + dfs(root->left, sum - root->val)
// 			 + dfs(root->right, sum - root->val);
// }

int pathSum(struct TreeNode* root, int sum) {
    int count = 0;
    int stack[1000]
    
}

int dfs(struct TreeNode* root, int sum){
	if(root == NULL)
		return 0;
	n
}