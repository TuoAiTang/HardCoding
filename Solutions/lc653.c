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

bool contains(int* list, int val, int index){
    for (int i = 0; i < index; ++i)
        if(list[i] == val)
            return 1;
    return 0;
}

bool find(struct TreeNode* root, int k, int* list, int* index){
    if(root == NULL)
        return 0;
    if(contains(list, k - root->val, *index))
        return 1;
    list[(*index) ++] = root->val;

    return find(root->left, k, list, index) || find(root->right, k, list, index);
}

void treeToArray(int* array, struct TreeNode* root, int* index){
    if(root == null)
        return;
    treeToArray(array, root->left, index);
    array[(*index) ++] = root->val;
    treeToArray(array, root->right, index);
}

bool findTarget(struct TreeNode* root, int k) {
    int list[10000];
    int index = 0;
    treeToArray(list, root, &index);

    int l = 0;
    int r = index - 1;

    while(l < r){
        int sum = list[l] + list[r];
        if(sum == k)
            return 1;
        if(sum < k)
            l++;
        else
            r--;
    }
    
    return 0;
}



