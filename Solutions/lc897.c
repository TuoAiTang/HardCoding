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

struct TreeNode* increasingBST(struct TreeNode* root) {
    struct TreeNode** cur = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
    struct TreeNode* newTree = (struct TreeNode*)maloc(sizeof(struct TreeNode));
    *cur = newTree;
    inorderChangeRight(cur, root);
    return newTree->right;

}
//cur points to a TreeNode Pointer
void inorderChangeRight(struct TreeNode** cur, struct TreeNode* root){
	if(root == null)
		return;
	inorderChangeRight(cur, root->left);
	//in-place change
	root->left = NULL;
	(*cur)->right = root;
	//cur points to the root now
	*cur = root;
	inorderChangeRight(cur, root->right);
}