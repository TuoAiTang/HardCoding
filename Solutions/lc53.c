//4ms beats 100%
//Time: O(n)
//Space: O(1)
int maxSubArray2(int* nums, int numsSize) {
	int maxSum = INT_MIN;
	int thisSum = 0;
    for(int i = 0 ; i < numsSize; i++){
    	thisSum += nums[i];
    	if(thisSum > maxSum)
    		maxSum = thisSum;
    	if(thisSum < 0)
    		thisSum = 0;
    }
    return maxSum;
}


int max(int a, int b){
	return a > b ? a : b;
}

int maxSub(int* nums, int start, int end){
	if(start == end) return nums[start];
	int mid = (start + end) / 2;
	int leftSum = maxSub(nums, start, mid);
	int rightSum = maxSub(nums, mid + 1, end);
	int leftBoarderSum = 0;
	int maxLeftBoarderSum = INT_MIN;
	int rightBoarderSum = 0;
	int maxRightBoarderSum = INT_MIN;
	for(int i = mid; i >= start; i--){
		leftBoarderSum += nums[i];
		maxLeftBoarderSum = max(maxLeftBoarderSum, leftBoarderSum);
	}
	for(int i = mid + 1; i <= end; i++){
		rightBoarderSum += nums[i];
		maxRightBoarderSum = max(maxRightBoarderSum, rightBoarderSum);
	}
	int midSum = maxLeftBoarderSum + maxRightBoarderSum;
	return max(max(leftSum, rightSum), midSum);
}


//Time: O(nlogn)
//Space: O()
//Runtime: 8ms beats 23%
int maxSubArray(int* nums, int numsSize) {
	return maxSub(nums, 0, numsSize - 1);
}