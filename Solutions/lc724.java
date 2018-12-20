class lc724 {
	//prefix-sum dp O(n)
	//15ms beats 92.32%
    public int pivotIndex(int[] nums) {
    	int n = nums.length;
    	if(n == 0) return -1;
        for(int i = 1; i < n; i++)
        	nums[i] += nums[i - 1];

        if(nums[n - 1] - nums[0] == 0) return 0;
        for(int i = 1; i < n; i++)
        	//leftSum == rightSum
        	if(nums[i - 1] == (nums[n - 1] - nums[i]))
        		return i;

        return -1;
    }	
}