/*	131ms beats 82.87%
**	Time: O(n) -> preprocess + O(m * 1) m->query times
**	Space: O(n)
*/
import java.util.*;
class lc303{

}
class NumArray {

	private int [] sums;

    public NumArray(int[] nums) {
    	int n = nums.length;
    	if(n == 0 ) return;
        sums = new int[n];
        sums[0] = nums[0];
        for(int i = 1; i < n; i++)
        	sums[i] = sums[i - 1] + nums[i];
    }
    
    public int sumRange(int i, int j) {
        if(i == 0) return sums[j];
        return sums[j] - sums[i - 1];
    }

}
