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

//NULL -> -1
int getHeight(AvlTree T){
	if(!T)
		return -1;
	else
		return T->height;
}

AvlTree SingleRotateWithLeft(AvlTree k2){
	Position k1;

	k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;

	k2->height = max(getHeight(k2->left), getHeight(k2->right)) + 1;
	k1->height = max(getHeight(k1->left), getHeight(k1->right)) + 1;
	return k1;
}

AvlTree SingleRotateWithRight(AvlTree k2){
	Position k1;

	k1 = k2->right;
	k2->right = k1->left;
	k1->left = k2;

	k2->height = max(getHeight(k2->left), getHeight(k2->right)) + 1;
	k1->height = max(getHeight(k1->left), getHeight(k1->right)) + 1;
	return k1;
}

AvlTree DoubleRotateWithLeft(AvlTree k3){
	k3->left = SingleRotateWithRight(k3->left);
	return SingleRotateWithLeft(k3);
}

AvlTree DoubleRotateWithRight(AvlTree k3){
	k3->right = SingleRotateWithLeft(k3->right);
	return SingleRotateWithRight(k3);
}

//return the new root 
AvlTree insert(ElementType X, AvlTree T){
	if(!T){
		T = (AvlTree)malloc(sizeof(struct TreeNode));
		if(!T)
			return NULL;
		T->left = T->right = NULL;
		T->val = X;
		T->height = 0;
	}
	else if(X < T->val){		
		T->left = insert(X, T->left);
		if(getHeight(T->left) - getHeight(T->right) == 2){
			if(X < T->left->val)
				T = SingleRotateWithLeft(T);
			else
				T = DoubleRotateWithLeft(T);
		}
	}
	else if(X > T->val){
		T->right = insert(X, T->right);
		if(getHeight(T->right) - getHeight(T->left) == 2){
			if(X > T->right->val)
				T = SingleRotateWithRight(T);
			else
				T = DoubleRotateWithRight(T);
		}
	}
	//if X == T->val, do nothing;

	T->height = max(getHeight(T->left), getHeight(T->right)) + 1;
	return T;
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

Position FindMin(AvlTree t){
	if(!t)
		return NULL;
	else if(!t->left)
		return t;
	else
		return FindMin(t->left);
}

Position FindMax(AvlTree t){
	if(!t)
		return NULL;
	else if(!t->right)
		return t;
	else
		return FindMax(t->right);
}

AvlTree Delete(AvlTree t, ElementType val){
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

void PrintTreeCenOrder(AvlTree t){
	if(t){
		PrintTreeCenOrder(t->left);
		printf("%d\t", t->val);
		PrintTreeCenOrder(t->right);
	}
}

void PrintTreePreOrder(AvlTree t){
	if(t){
		printf("%d\t", t->val);
		PrintTreePreOrder(t->left);		
		PrintTreePreOrder(t->right);
	}
}

void InorderTraversalByStack(AvlTree root){
	if(root == NULL)
		return;
	AvlTree* stack = (AvlTree*)malloc(100 * sizeof(AvlTree));
	int top = -1;
	struct TreeNode* p = root;
	stack[++top] = p;
	while(top != -1){
		while((stack[top])->left){
			p = stack[top];
			stack[++top] = p->left;
		}
		while(top != -1){
			p = stack[top--];
			printf("%d\t", p->val);
			if(p->right){
				stack[++top] = p->right;
				break;
			}
		}
	}
	free(stack);	
}

// void PreOrderTraversalByStack(AvlTree root){
// 	struct TreeNode* stack = (struct TreeNode*)malloc(100 * sizeof(struct TreeNode));
// 	int top = -1;
// 	struct TreeNode* p = root;
// 	while(p){
// 		if(p->left == NULL){
// 			printf("%d\t", p->val);
// 			p = p->right;
// 			if(p == NULL){
// 				while((stack[top]).right == NULL && top != -1)
// 					top--;
// 				if(top != -1)		
// 					p = (stack[top--]).right;				
// 			}
// 		}
// 		else{
// 			stack[++top] = *p;
// 			printf("%d\t", (stack[top]).val);	
// 			p = p->left;
// 		}
// 	}
// 	free(stack);
// }//

// int* PreOrderTraversalByStack(struct TreeNode* root, int* returnSize){
// 	if(!root)
// 		return NNULL;
// 	struct TreeNode** stack = (struct TreeNode**)malloc(100 * sizeof(struct TreeNode*));
// 	int top = -1;
// 	stack[++top] = root;
// 	int* res = (int*)malloc(10000 * sizeof(int));
// 	*returnSize = 0;
// 	while(top != -1){
// 		struct TreeNode* p = stack[top--];
// 		res[(*returnSize) ++] = p->val;
// 		if(p->right)
// 			stack[++top] = p->right;
// 		if(p->left)
// 			stack[++top] = p->left;		
// 	}
// 	free(stack);
// 	return res;
// }


void PostOrderTraversalByStack(AvlTree root){
	if(root == NULL)
		return;
	AvlTree* stack = (AvlTree*)malloc(100 * sizeof(AvlTree));
	int top = -1;
	struct TreeNode* pCur = NULL;
	struct TreeNode* pLast = NULL;
	stack[++top] = pCur;
	while(top != -1){
		pCur = stack[top];
		if(pCur->left != NULL && pLast != pCur->left && pLast != pCur->right)
			stack[++top] = pCur->left;
		else if(pCur->right != NULL && pLast != pCur->right)
			stack[++top] = pCur->right;
		else{
			printf("%d\t", (stack[top--])->val);
			pLast = pCur;
		}
	}
	
	free(stack);
}

int main(){

	int a[] = {5,2,1,6,4,3,7,8};
	AvlTree T1 = NULL;
	for (int i = 0; i < 8; ++i)
		T1 = insert(a[i], T1);


	puts("CenterOrder: \n");
	InorderTraversalByStack(T1);


	puts("\n\n----------\n");
	puts("PostOrder: \n");
	PostOrderTraversalByStack(T1);

	int* columnSizes = (int*)malloc(1000 * sizeof(int*));
	int returnSize = 0;
	int** res = pathSum(T1, 4, columnSizes, &returnSize);
	for(int i = 0; i < returnSize; i++){
		for(int j = 0; j < columnSizes[returnSize]; j ++)
			printf("%d->", res[i][j]);
		printf("\n");
	}
	
	return 0;
}
