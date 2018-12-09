/*	Straight forward, we can cost nlogn time to sort the array,
**	and then find the missing position.
**	However, the missing positive in [1, n + 1]
**	We split the array into two groups:
**		1.nums[i] > n 	(greater)
**		2.nums[i] <= n 	(less)
**	For group 1, we ignore, the missing positive must <= n + 1,
**	For group 2, we replace the position (nums[nums[i] - 1] == nums[i]) by swapping.
**	Then check it as a partial-sorted array before nums[i] > n.

**	Runtime: 0ms beats 100%
*/

int firstMissingPositive(int* nums, int numsSize) {
	int tmp;
	//while loop execute numSize times at most -> O(n)
    for(int i = 0; i < numsSize; i++){   	
    	while(nums[i] > 0 && nums[i] <= numsSize && nums[nums[i] - 1] != nums[i]){
    		tmp = nums[nums[i] - 1];
    		nums[nums[i] - 1] = nums[i];
    		nums[i] = tmp;
    	}
    }
    for(int i = 0; i < numsSize; i++)
    	if(nums[i] != i + 1)
    		return i + 1;
	return numsSize + 1;
}