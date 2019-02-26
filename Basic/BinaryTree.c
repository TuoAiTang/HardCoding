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

//return the new root 
SearchTree insert(ElementType X, SearchTree T){
	if(!T){
		T = (SearchTree)malloc(sizeof(struct TreeNode));
		if(!T)
			return NULL;
		T->left = T->right = NULL;
		T->val = X;
	}
	else if(X < T->val)
		T->left = insert(X, T->left);
	else if(X > T->val)
		T->right = insert(X, T->right);
	//if X == T->val, do nothing;

	return T;
}

// void printTree(SearchTree T, int height){

// }

int getHeight(SearchTree T){
	if(!T)
		return -1;
	int leftHeight, rightHeight;
	leftHeight = getHeight(T->left) + 1;
	rightHeight = getHeight(T->right) + 1;

	return max(leftHeight, rightHeight);
}

struct TreeNode* Find(struct TreeNode* root, ElementType val) {
    if(!root)
    	return NULL;
    if(val < root->val)
    	return Find(root->left, val);
    else if(val > root->val)
    	return Find(root->right, val);
    else
    	return root;
}

Position FindMin(SearchTree t){
	if(!t)
		return NULL;
	else if(!t->left)
		return t;
	else
		return FindMin(t->left);
}

Position FindMax(SearchTree t){
	if(!t)
		return NULL;
	else if(!t->right)
		return t;
	else
		return FindMax(t->right);
}

SearchTree Delete(SearchTree t, ElementType val){
	Position tmp = NULL;
	if(!t)
		return NULL;
	else if(val > t->val)
		Delete(t->right, val);
	else if(val < t->val)
		Delete(t->left, val);
	else if(t->left && t->right){
		tmp = FindMin(t->right);
		t->val = tmp->val;
		t->right = Delete(t->right, t->val);
	}
	else{
		tmp = t;
		t = t->left ? t->left : t->right;
		free(tmp);
	}
	return t;
}

void PrintTreeInOrder(SearchTree t){
	if(t){
		PrintTreeInOrder(t->left);
		printf("%d\t", t->val);
		PrintTreeInOrder(t->right);
	}
}

void PrintTreePreOrder(SearchTree t){
	if(t){
		printf("%d\t", t->val);
		PrintTreePreOrder(t->left);		
		PrintTreePreOrder(t->right);
	}
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
	*returnSize = 0;
	int* res = (int*)malloc(10000 * sizeof(int));
    struct TreeNode* p = root, *tmp = NULL;
    while(p){
    	if(p->left == NULL){
    		(*returnSize)++;
    		res[*returnSize - 1] = p->val;
    		p = p->right;
    	}
    	else{
    		tmp = p->left;
    		while(tmp->right != NULL && tmp->right != p)
    			tmp = tmp->right;
    		if(tmp->right == NULL){
    			tmp->right = p;
    			p = p->left;
    		}
    		else{
    			(*returnSize)++;
    			res[*returnSize - 1] = p->val;
    			tmp->right = NULL;
    			p = p->right;
    		}
    	}
    }
    return res;
}

int* inorderTraversalByStack(SearchTree root, int* returnSize){
	*returnSize = 0;
	int* res = (int*)malloc(10000 * sizeof(int));

	//stack size is O(h) h represents the height of root
	struct TreeNode* stack = (struct TreeNode*)malloc(10000 * sizeof(struct TreeNode));
	int top = -1;
	struct TreeNode* p = root;
	while(p){
		if(p->left == NULL){
    		res[++(*returnSize) - 1] = p->val;
			p = p->right;
			if(p == NULL){
				while((stack[top]).right == NULL && top != -1)
					res[++(*returnSize) - 1] = (stack[top--]).val;
				if(top != -1){
					res[++(*returnSize) - 1] = (stack[top]).val;		
					p = (stack[top--]).right;
				}					
			}
		}
		else{
			stack[++top] = *p;
			p = p->left;
		}
	}
	free(stack);
	return res;
}


void PrintMorrisTraversal(SearchTree root){
	struct TreeNode* p = root, *tmp = NULL;
    while(p){
    	if(p->left == NULL){
    		printf("%d\t", p->val);
    		p = p->right;
    	}
    	else{
    		tmp = p->left;
    		while(tmp->right != NULL && tmp->right != p)
    			tmp = tmp->right;
    		if(tmp->right == NULL){
    			tmp->right = p;
    			p = p->left;
    		}
    		else{
    			printf("%d\t", p->val);
    			tmp->right = NULL;
    			p = p->right;
    		}
    	}
    }
}

void inorder(SearchTree t){
	if(!t) return;
	SearchTree* stack = (SearchTree*)malloc(100 * sizeof(SearchTree));
	int top = -1;
	stack[++top] = t;
	SearchTree p = t;
	while(top != -1){
		while(p->left){
			p = p->left;
			stack[++top] = p;
		}
		while(top != -1){
			printf("%d\n", stack[top--]->val);
			if(p->right){
				stack[++top] = p->right;
				break;
			}
		}
	}
}

int main(){

	int a[] = {5,4,3,2,1};
	SearchTree T1 = NULL, T2 = NULL;
	for (int i = 0; i < 5; ++i)
		T1 = insert(a[i], T1);
	for (int i = 0; i < 7; ++i)
		T2 = insert(5-i, T2);


	// puts("CenterOrder: \n");
	// PrintTreeCenOrder(T1);

	// puts("\n\n----------\n");

	// puts("PreOrder: \n");
	// PrintTreePreOrder(T1);

	// printf("isSameTree:%d\n", isSameTree(T1, T2));

	// int size;
	// int* res = inorderTraversalByStack(T1, &size);
	// for (int i = 0; i < size; ++i)
	// 	printf("%d\t", res[i]);
	// free(res);

	inorder(T1);

	// inorderTraversalByStack(T1);

	return 0;
}
