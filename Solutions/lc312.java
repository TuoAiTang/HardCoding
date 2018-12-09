import java.util.*;
class lc312 {
	/*	Solution 1: DP
	**	Time: O(n^3)
	**	Space: O(n^2)
	** 	Runtime: 10 ms beats 44.34 %
	*/
    public int maxCoins(int[] nums) {
    	int n = nums.length;
        int [] Nums = new int [n + 2];
        Nums[0] = Nums[n + 1] = 1;
        for(int i = 1; i <= n; i++)
        	Nums[i] = nums[i - 1];

        //dp[i][j] -> maxCoins(nums[i], nums[j]);
        //init 0, default
        int [][] dp = new int [n + 2][n + 2];
        for(int l = 1; l <= n; l++){
        	for(int i = 1; i <= n - l + 1; i++){
        		int j = i + l - 1;
        		for(int k = i; k <= j; k++){
        			//for i >= j , dp[i][j] = 0;
        			dp[i][j] = Math.max(dp[i][j],
        			 					dp[i][k - 1] + dp[k + 1][j]) +
        								Nums[i - 1] * Nums[k] * Nums[j + 1];
        		}
        	}
        }

        return dp[1][n];
    }

    //Solution 2: Memorization Recursion
    //Time: O(n^3)
    //Space: O(n^2 + n) n -> recursion depth
    //Runtime: 7ms beats 68.21%
    public int maxCoins2(int[] nums) {
    	int n = nums.length;
        int [] Nums = new int [n + 2];
        Nums[0] = Nums[n + 1] = 1;
        for(int i = 1; i <= n; i++)
        	Nums[i] = nums[i - 1];

        //dp[i][j] -> maxCoins(nums[i], nums[j]);
        //init 0, default
        int [][] dp = new int[n + 2][n + 2];

        return dfs(1, n, Nums, dp);
    }

    private int dfs(int i, int j, int [] nums, int [][] dp){
    	if(i > j) return 0;
    	if(i == j) return nums[i - 1] * nums[i] * nums[i + 1];
    	if(dp[i][j] > 0) return dp[i][j];
    	int ans = 0;
    	for(int k = i; k <= j; k++)
    		ans = Math.max(ans, dfs(i, k - 1, nums, dp)
    							+ nums[i - 1] * nums[k] * nums[j + 1]
    							+ dfs(k + 1, j, nums, dp));
    	dp[i][j] = ans;
    	return ans;
    }
}