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

bool isSymmetric(struct TreeNode* root) {
    if(root == NULL)
    	return false;
    struct TreeNode** stack = (struct TreeNode**)malloc(10000 * sizeof(struct TreeNode*));
    int top = -1;
    stack[++top] = root;
    int layer = 0;
    while(top != -1){
    	int size = top + 1;
    	if(size != (1 << layer))
    		return false;
    	int* levelList = (int*)malloc(sizeof(size/2));

    	for (int i = 0; i < size/2; ++i)
    	{
    		struct TreeNode p = stack[top--];
    		levelList[i] = p->val;
    		if(p->left)
    			stack[++top]
    	}
    }
}

int main(){


	printf("%d\n", 3 << 3);
	return 0;
}