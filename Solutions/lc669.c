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

typedef struct TreeNode* SearchTree;
typedef struct TreeNode* Position;

struct TreeNode* trimBST(struct TreeNode* root, int L, int R) {
    if(root){
    	if(root->val < L)
    		root = trimBST(root->right, L, R);
    	else if(root->val > R)
    		root = trimBST(root->left, L, R);
    	if(root){
    		root->left = trimBST(root->left, L, R);
    		root->right = trimBST(root->right, L, R);
    	}
    }
    return root;
}

struct TreeNode* trimBST(struct TreeNode* root, int L, int R) {
   	if(!root)
   		return NULL;
   	if(root->val < L){
   		root->right = trimBST(root->right, L, R);
   		return root->right;
   	}
   	if(root->val > R){
   		root->left = trimBST(root->left, L, R);
   		return root->left;
   	}
    root->left = trimBST(root->left, L, R);
    root->right = trimBST(root->right, L, R);

    return root;
}

void freeTreeNode(struct TreeNode* t){
	if(t){
		if(!t->left && !t->right)
			free(t);
		else{
			freeTreeNode(t->left);
			t->left = NULL;
			freeTreeNode(t->right);
			t->right = NULL;
			freeTreeNode(t);
		}		
	}
}