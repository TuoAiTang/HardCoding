void helperWithStack(struct TreeNode* root, int sum, int** ans, int** columnSizes, int* returnSize, int* stack, int* top){
	if(root == NULL) return;
	//leaf node
	if(!root->left && !root->right){
		if(root->val == sum){
			stack[++(*top)] = root->val;
			//one more path found
			//copy stack's conte
			int* path = (int*)malloc(((*top) + 1) * sizeof(int));,
			for(int i = 0; i < *top + 1; i++){
				path[i] = stack[i];
			}
			(*columnSizes)[*returnSize] = *top + 1;
			ans[(*returnSize) ++] = path;
			(*top)--;			
		}
        return;
	}
	//not leaf node
	stack[++(*top)] = root->val;
	int new_sum = sum - root->val;
	helperWithStack(root->left, new_sum, ans, columnSizes, returnSize, stack, top);
	helperWithStack(root->right, new_sum, ans, columnSizes, returnSize, stack, top);
	(*top)--;
}
int** pathSum(struct TreeNode* root, int sum, int** columnSizes, int* returnSize) {
	int** ans = (int**)malloc(1000 * sizeof(int*));
	int* stack = (int*)malloc(1000 * sizeof(int));
    *returnSize = 0;
    *columnSizes = (int*)malloc(500 * sizeof(int));
    (*columnSizes)[*returnSize] = 0;
	int top = -1;
    helperWithStack(root, sum, ans, columnSizes, returnSize, stack, &top);
    free(stack);
    return ans;
}