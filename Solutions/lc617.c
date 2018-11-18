#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <AVL-BST.c>

struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2) {
    if(!t1)
    	return t2;
    if(!t2)
    	return t1;
    t1->val += t2->val;
    t1->left = mergeTrees(t1->left, t2->left);
    t1->right = mergeTrees(t1->right, t1->right);
    return t1;
}

int main(){

}