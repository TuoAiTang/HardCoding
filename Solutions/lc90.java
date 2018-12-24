import java.util.*;
class lc90 {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Set<List<Integer>> set = new HashSet<>(); 
    	int n = nums.length;
    	for(int i = 0; i < (1 << n); i++){
    		List<Integer> cur = new ArrayList<>();
    		for(int j = 0; j < n; j++)
    			if((i & (1 << j)) != 0)
    				cur.add(nums[j]);
			set.add(cur);
    	}
    	return new ArrayList<>(set);
    }
}