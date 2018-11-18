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

int Max(int a, int b){
	return a > b ? a : b;
}

//O(nlogn)
// bool isBalanced(struct TreeNode* root) {
//     if(root == NULL)
//     	return true;
//     int lh = height(root->left);
//     int rh = height(root->right);

//     return (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right));
// }
// int height(struct TreeNode* t){
// 	if(t == NULL)
// 		return -1;
// 	return Max(height(t->left), height(t->right)) + 1;
// }

