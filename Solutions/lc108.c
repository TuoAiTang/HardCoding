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
struct TreeNode* helper(int* nums, int l, int r){
	if(l > r)
		return NULL;
	int middle = (l + r) / 2;
	struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));	
	node->val = nums[middle];
	node->left = helper(nums, l, middle - 1);
	node->right = helper(nums, middle + 1, r);
	return node;
}
struct TreeNode* sortedArrayToBST(int numsSize) {
    return helper(root, nums, 0, numsSize - 1);
}