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
	int height;
};

typedef struct TreeNode* AvlTree;
typedef struct TreeNode* Position;

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
	int i = 0;
    int* leaves1 = (int*)malloc(100 * sizeof(int));
    dfs(leaves1, root1, &i);

    int j = 0;
    int* leaves2 = (int*)malloc(100 * sizeof(int));
    dfs(leaves2, root2, &j);

    if(i != j)
    	return 0;

    for(int k = 0; k < j; k ++)
    	if(leaves1[k] != leaves2[k])
    		return 0;

	return 1;  
}

void dfs(int* leaves, struct TreeNode* root, int* index){
	if(root){
        
		if(!root->left && !root->right)
			leaves[(*index)++] = root->val;	
        
		dfs(leaves, root->left, index);
		dfs(leaves, root->right, index);
	}
}





int main(){

	
	
	return 0;
}
