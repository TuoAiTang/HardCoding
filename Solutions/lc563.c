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

//return the sum of root,left + right + node->val
int sumHelper(struct TreeNode* root, int* tilt){
	if(root == NULL)
		return 0;
	int left = sumHelper(root->left, tilt);
	int right = sumHelper(root->right, tilt);
	*tilt += abs(left - right);
	return left + right + root->val;
}

int findTilt(struct TreeNode* root) {
    int tilt = 0;
    sumHelper(root, &tilt);
    return tilt;
}

int main(){

	struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));	
	node->val = 3;
	node->left = node->right = NULL;

	printf("%d\n", findTilt(node));


	return 0;
}