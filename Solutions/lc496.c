#include <stdio.h>
#include <stdlib.h>


int* nextGreaterElement(int* findNums, int findNumsSize, int* nums, int numsSize, int* returnSize) {
    *returnSize = findNumsSize;
    int stack[1000] = {0};
//    int *ret = (int*)malloc(findNumsSize * sizeof(int));
	int ret[1000] = {0}; 
    int top = -1;
    int max = nums[0];
    int min = nums[0];
    for(int i = 0; i < numsSize; i ++){
    	max = max > nums[i] ? max : nums[i];
    	min = min < nums[i] ? min : nums[i];
	}
    int *map = (int*)malloc((max - min + 1) * sizeof(int));
    for (int i = 0; i < numsSize; ++i)
    {
    	while(top != -1 && stack[top] < nums[i])
    		map[stack[top--]] = nums[i];

    	stack[++top] = nums[i];
    }

    while(top > -1)
    	map[stack[top--]] = -1;

    for (int i = 0; i < *returnSize; ++i)
    	ret[i] = map[findNums[i]];

    free(map);

    return ret;
}

int main()
{
	int nums1[3] = {3, 4, 1};
	int nums2[4] = {1, 3, 4, 2};
	int returnSize;
	int *res = nextGreaterElement(nums1, 3, nums2, 4, &returnSize);
	for (int i = 0; i < returnSize; ++i)
	{
		printf("%d\n", res[i]);
	}
	return 0;
}
