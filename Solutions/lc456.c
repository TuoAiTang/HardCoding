#include <stdio.h>
#include <stdlib.h>
// start 17:02 
// end 18:45
bool find132pattern(int* nums, int numsSize) {

    if(numsSize < 3)
        return 0;

    int* stack = (int*)malloc(numsSize * sizeof(int));
    int top = -1;

    int* min = (int*)malloc(numsSize * sizeof(int));
    min[0] = nums[0];

    for (int i = 1; i < numsSize; ++i)
        min[i] = min[i-1] < nums[i] ? min[i -1] : nums[i];

    for (int j = numsSize - 1; j >= 0; j--)
    {
        if(nums[j] > min[j]){
            while(top != -1 && stack[top] <= min[j])
                top--;
            if(top != -1 && nums[j] > stack[top])
                return true;
            stack[++top] = nums[j];
        }
    }

    free(stack);
    free(min);

    return 0;
}

int main(){


	int a[] = {3, 1, 2, 4};

	printf("%d\n", find132pattern(a, 4));

	return 0;
}