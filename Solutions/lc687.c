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
//root must be used
//return one side only
//update ans both sides
int univalPath(struct TreeNode* root, int* ans){
	if(root == NULL) return 0;
	int l = univalPath(root->left, ans);
	int r = univalPath(root->right, ans);

	int ret_l = 0;
	int ret_r = 0;

	if(root->left && root->val == root->left->val)
		ret_l = l + 1;
	if(root->right && root->val == root->right->val)
		ret_r = r + 1;

	*ans = Max(ans, ret_l + ret_r); //both sides
	return Max(ret_l, ret_r); //one side
}
int longestUnivaluePath(struct TreeNode* root) {
    int ans = 0;
    univalPath(root, &ans);
    return ans;
}

