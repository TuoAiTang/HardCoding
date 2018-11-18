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

int getMinimumDifference(struct TreeNode* root) {
    int res[10000];
    int index = 0;
    inorder(root, res, &index);
    int minDiff = INT_MAX;
    for(int i = 1; i < index; i++){
    	minDiff = MIN(minDiff, res[i] - res[i-1]);
    }
    return minDiff;
}

void inorder(struct TreeNode* root, int* res, int* index){
	if(root){
		inorder(root->left, res, index);
		res[(*index) ++] = root->val;
		inorder(root->right, res, index);
	}
}