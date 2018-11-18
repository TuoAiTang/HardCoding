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

//m, size of s which is bigger; n, size of t which is smaller; 
//Time: O(n^2)

//Time: O(n)
bool isSameTree(struct TreeNode* s, struct TreeNode* t){
	if(!s && !t) return true;
	if(!s || !t) return false;
	return ((s->val == t->val) && isSameTree(s->left, t->left) && isSameTree(s->right, t->right));
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t) {
	if(s == NULL) return false;
    if(isSameTree(s, t)) return true; //O(n)
    return isSubTree(s->left, t) || isSubTree(s->right, t); //O(m * n)
}

