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


//Morris
struct TreeNode* convertBST(struct TreeNode* root) {
	struct TreeNode* p = root, *tmp = NULL;
	int sum = 0;
	while(p){
		if(p->right == NULL){
			sum += p->val;
			p->val = sum;
			p = p->left;
		}
		else{
			tmp = p->right;
			while(tmp->left != NULL && tmp->left != p)
				tmp = tmp->left;
			if(tmp->left == NULL){
				tmp->left = p;
				p = p->right;
			}
			else{
				tmp->left = NULL;
				sum += p->val;
				p->val = sum;
				p = p->left;
			}
		}
	}
	return root;
}

//stack 1
struct TreeNode* convertBST(struct TreeNode* root) {
	if(root == NULL)
		return root;
	struct TreeNode** stack = (struct TreeNode**)malloc(100 * sizeof(struct TreeNode*));
	int top = -1;
	struct TreeNode* node = root;
	int sum = 0;
	while(top != -1 || node != NULL){
		while(node != NULL){
			stack[++top] = node;
			node = node->right;
		}

		node = stack[top--];
		sum += node->val;
		node->val = sum;

		node = node->left;
	}
	return root;
}

//stack 2
struct TreeNode* convertBST(struct TreeNode* root) {
	if(root == NULL)
		return root;
	struct TreeNode** stack = (struct TreeNode**)malloc(100 * sizeof(struct TreeNode*));
	int top = -1;
	stack[++top] = root;
	struct TreeNode* tmp;
    int sum = 0;
	while(top != -1){
		while(stack[top]->right){
			tmp = stack[top];
			stack[++top] = tmp->right;
		}

		while(top != -1){
			tmp = stack[top--];
            sum += tmp->val;
            tmp->val = sum;
			if(tmp->left){
				stack[++top] = tmp->left;
				break;
			}
		}
	}
	return root;
}

//recursive
struct TreeNode* convertBST(struct TreeNode* root) {
	int sum = 0;
	helper(root, &sum);
    return root;
}

void helper(struct TreeNode* t, int* sum){
	if(t == NULL)
		return;
	helper(t->right, sum);
	*sum += t->val;
	t->val = *sum;
	helper(t->left, sum);
}


























int sumOfTree(struct TreeNode* root){
	if(root == NULL)
		return 0;

	int sum = 0;
	sum += sumOfTree(root->left) + root->val + sumOfTree(root->right);

	return sum;
}