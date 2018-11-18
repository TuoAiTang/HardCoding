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

bool validHelper(struct TreeNode* root, long long int min, long long int max){
	if(root == NULL)
		return true;
	if(root->val <= min || root->val >= max)
		return false;
	if(validHelper(root->left, min, root->val) && validHelper(root->right, root->val, max))
		return true;
	return false;
}
bool isValidBST(struct TreeNode* root) {
    return validHelper(root, LLONG_MIN, LLONG_MAX);
}





int main(int argc, char const *argv[])
{
	return 0;
}