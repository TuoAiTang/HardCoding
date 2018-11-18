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

int maxRetOneSide(struct TreeNode* root, int* ans){
	if(root == NULL) return 0;
	int left = maxRetOneSide(root->left, ans);
	int right = maxRetOneSide(root->right, ans);

	int max = 0;
	int maxLR = Max(left, right);
	if(left >= 0 && right >= 0)
		max = left + right + root->val;
	else
		max = maxLR > 0 ? maxLR + root->val : root->val;

	*ans = Max(*ans, max);

	return maxLR > 0 ? maxLR + root->val : root->val;
}
int maxPathSum(struct TreeNode* root) {
    int ans = INT_MIN;
    maxRetOneSide(root, &ans);
    return ans;
}

