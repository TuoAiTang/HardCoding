//27ms beats 48.22%
import java.util.*;
class lc673 {
    public int findNumberOfLIS(int[] nums) {
        int n = nums.length;
        if(n == 0) return 0;
        //c[i] -> the number of LIS ends with nums[i]
        //l[i] -> the max length of LIS ends with nums[i]
        int [] c = new int [n];
        Arrays.fill(c, 1);
        int [] l = new int [n];
        Arrays.fill(l, 1);

        int max_len = 1;
        int ans = 0;
        for(int i = 0; i < n; i++){
        	for(int j = 0; j < i; j++){
        		if(nums[i] > nums[j]){
        			if(l[j] + 1 > l[i]){
        				l[i] = l[j] + 1;
        				c[i] = c[j];
        			}
        			else if(l[j] + 1 == l[i]){
        				c[i] += c[j];
        			}
        		}
        	}

        	if(l[i] > max_len){
        		max_len = l[i];
        		ans = c[i];
        	} else if(l[i] == max_len){
        		ans += c[i];
        	}

        }
        return ans;
    }
}