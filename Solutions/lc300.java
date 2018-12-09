import java.util.*;
class lc300 {
	//Soluiton: dp
	//Time: O(n^2)
	//Space: O(n)
	//12ms beats 64.41%
    public int lengthOfLIS(int[] nums) {
    	int n = nums.length;
        int [] dp = new int [n];
        Arrays.fill(dp, 1);
        for(int i = 0; i < n; i++)
        	for(int j = 0; j < i; j++)
        		if(nums[i] > nums[j])
        			dp[i] = Math.max(dp[i], dp[j] + 1);
		int ans = 0;
		for(int d : dp)
			ans = Math.max(ans, d);
		return ans;
    }

    //Soluiton: MR
	//Time: O(n^2)
	//Space: O(n)
	//7ms beats 65.08%
    public int lengthOfLIS2(int[] nums) {
    	int n = nums.length;
    	if(n == 0) return 0;
        int [] mem = new int [n];
		int ans = 1;
		for(int i = 0; i < n; i++)
			ans = Math.max(ans, LIS(nums, i, mem));
		return ans;
    }

    private int LIS(int [] nums, int end, int [] mem){
    	if(end == 0) return 1;
    	if(mem[end] > 0) return mem[end];

    	int ans = 1;
    	for(int i = 0; i < end; i++)
    		if(nums[end] > nums[i])
    			ans = Math.max(ans, LIS(nums, i, mem) + 1);
		mem[end] = ans;
		return ans;
    }
}