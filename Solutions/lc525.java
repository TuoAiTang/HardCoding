package hashtable;
import java.util.*;
public class lc525 {
	public int findMaxLength(int[] nums) {
		int ans = 0;
		if(nums.length < 2)
			return ans;
        for (int i = 0; i < nums.length; i++) {
			if(nums[i] == 0)
				nums[i] = -1;
		}
        int []sum = new int[nums.length];
        sum[0] = nums[0];
        for(int i = 1; i < nums.length; i++) {
        	sum[i] = sum[i - 1] + nums[i];
        }
        Map<Integer, Integer> hm = new HashMap<>();
        for (int i = 0; i < sum.length; i++) {
			if(!hm.containsKey(sum[i]))
				hm.put(sum[i], i);
			ans = Math.max(ans, i - hm.get(sum[i]));
		}       
        return ans;
    }
	public static void main(String[] args) {
		int [] nums = {1,0,0,0,1,1,0,1};
		for (int i = 0; i < nums.length; i++) {
			if(nums[i] == 0)
				nums[i] = -1;
		}
		for(int i : nums)
			System.out.println(i);
		
	}
}
