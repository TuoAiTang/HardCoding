//12ms beats 100%
int totalHammingDistance(int* nums, int numsSize) {
    int ans = 0;
    int count = 0;
    for(int i = 0; i < 32; i++){
        count = 0;
    	for(int j = 0; j < numsSize; j++)
    		if(nums[j] & (1 << i))
                count++;
    	ans +=  (numsSize - count) * count;
    }
    return ans;
}