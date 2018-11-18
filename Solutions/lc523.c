#include <stdio.h>
#include <stdlib.h>

int* nextGreaterElements_2(int* nums, int numsSize, int* returnSize) {
	*returnSize = numsSize;
    int* res = (int*)malloc(numsSize * sizeof(int));
    int* stack = (int*)malloc(numsSize * sizeof(int));
    int top = -1;
    for (int i = 0; i < 2 * numsSize - 1; ++i)
    {
    	while(top != -1 && nums[i % numsSize] > nums[stack[top]])
    		res[stack[top--]] = nums[i % numsSize];
    	if(i < numsSize)
    		stack[++top] = i % numsSize;
   	}
   	while(top != -1)
   		res[stack[top--]] = -1;

   	free(stack);
   	return res;
}

int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {
	*returnSize = numsSize;
    int* res = (int*)malloc(numsSize * sizeof(int));
    int* stack = (int*)malloc(numsSize * sizeof(int));
    int top = -1;
    for (int i = 0; i < numsSize; ++i)
    {
    	while(top != -1 && nums[i] > nums[stack[top]])
    		res[stack[top--]] = nums[i];
		stack[++top] = i;
   	}

   	for (int i = 0; i < numsSize - 1; ++i)
   		while(top != -1 && nums[i] > nums[stack[top]])
    		res[stack[top--]] = nums[i];
    	
   	while(top != -1)
   		res[stack[top--]] = -1;

   	free(stack);
   	return res;
}

int main(){

	int a[] = {1,2,1,1,1,1};
	int size;

	int* b = nextGreaterElements(a, 6, &size);
	for (int i = 0; i < size; ++i)
	{
		printf("%d\n", b[i]);
	}



	return 0;
}