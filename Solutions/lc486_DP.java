//6ms beats 28.61%
import java.util.*;
class lc486_DP {
	//Time: O(n^2)
    public boolean PredictTheWinner(int[] nums) {
        int n = nums.length;
        int [][] dp = new int [n][n];

        int sum = 0;
        for(int i = n - 1; i >= 0; i--){
            //count the nums sum
            sum += nums[i];
            for(int j = i; j < n; j++){
                if(j == i) dp[i][j] = nums[i];
                else if(j == i + 1) dp[i][j] = Math.max(nums[i], nums[j]);
                //the next player will do the maximum choice too!
                //the sub-problems of dp[i + 2][j], dp[i + 1][j - 1],
                //dp[i + 1][j - 1], dp[i][j - 2] has been solved
                //since the outer-loop from right to left, 
                //the inner-loop from left to right.
                else{
                    int left = Math.min(dp[i + 2][j], dp[i + 1][j - 1]) + nums[i];
                    int right = Math.min(dp[i + 1][j - 1], dp[i][j - 2]) + nums[j];
                    dp[i][j] = Math.max(left, right);
                }
            }
        }
        return dp[0][n - 1] >= sum - dp[0][n - 1]; 
    }
}