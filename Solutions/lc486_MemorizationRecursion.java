//3ms beats 93.46%
import java.util.*;
class lc486_MemorizationRecursion {
    //Time: O(n^2) <- n^2, the number of sub-problems
    //Space: O(n^2 + n)  <- memo size;
    
    private int [] memo;

    public boolean PredictTheWinner(int[] nums) {
        int n = nums.length;
        memo = new int[n * n + n];
        Arrays.fill(memo, Integer.MIN_VALUE);
        return getScores(nums, 0, n - 1) >= 0;
    }
    
    private int getScores(int [] nums, int l, int r){
    	if(l == r) return nums[l];
        int key = l * nums.length + r;
        if(memo[key] != Integer.MIN_VALUE) return memo[key];
        memo[key] = Math.max(nums[l] - getScores(nums, l + 1, r),
    					nums[r] - getScores(nums, l, r - 1));
        return memo[key];
    }
}