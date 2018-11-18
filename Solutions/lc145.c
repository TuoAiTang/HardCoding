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

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
 	*returnSize = 0;
 	if(root == NULL) return NULL;
 	struct TreeNode** stack = (struct TreeNode**)malloc(100 * sizeof(struct TreeNode*));
 	int* res = (int*)malloc(10000 * sizeof(int));
 	int top = -1;
 	stack[++top] = root;
 	struct TreeNode* pLast = root;
 	struct TreeNode* pCur = root;
 	while(top != -1){
 		pCur = stack[top];
 		if(pCur->left && pLast != pCur->left && pLast != pCur->right)
 			stack[++top] = pCur->left;
 		else if(pCur->right && pLast != pCur->right)
 			stack[++top] = pCur->right;
 		else{
 			pLast = pCur;
 			res[(*returnSize) ++] = pCur->val;
 			top--;
 		}
 	}
 	free(stack);
 	return res;
}