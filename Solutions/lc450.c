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

struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if(root == NULL)
    	return root;
    if(root->val < key){
    	root->right = deleteNode(root->right, key);
    }
    else if(root->val > key){
    	root->left = deleteNode(root->left, key);
    }
    else{
    	if(root->left == NULL || root->right == NULL){
    		struct TreeNode* tmp = root;
    		root = root->left ? root->left : root->right;
    		free(tmp);
    		return root;
    	}
    	else{
    		struct TreeNode* new_root = root->right;   		
    		struct TreeNode* parent = root;
    		while(new_root->left){
    			parent = new_root;
    			new_root = new_root->left;
    		}
    		if(parent != root){
    			parent->right = new_root->right;
    			new_root->right = root->right;
    		}
    		new_root->left = root->left;
    		free(root);
    		return new_root;    		
    	}
    }
    return root;
}
