int searchInsert(int* nums, int numsSize, int target) {
    int start = 0;
    int end = numsSize - 1;
    while(start + 1 < end){
    	int mid = (start + end) / 2;
    	if(target == nums[mid])
    		return mid;
		if(target < nums[mid])
    		end = mid;
    	else
    		start = mid;
    }
    if(target <= nums[start])
    	return start;
    else if(target <= nums[end])
    	return end;
    else
    	return end + 1;
}