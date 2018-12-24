import java.util.*;
class lc78 {
	//Solution 1: dfs
	//3ms beats 10.46%
	//Time:(n * 2^n)
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> cur = new ArrayList<>();
        for(int i = 0; i <= nums.length; i++)
        	dfs(i, 0, ans, cur, nums);
        return ans;
    }

    //Time:O(2^n)
    private void dfs(int n, int s, List<List<Integer>> ans, List<Integer> cur, int [] nums){
    	if(cur.size() == n){
    		ans.add(new ArrayList<>(cur));
    		return;
    	}
    	for(int i = s; i < nums.length; i++){
    		cur.add(nums[i]);
    		dfs(n, i + 1, ans, cur, nums);
    		cur.remove(cur.size() - 1);
    	}   	
    }


	//Solution 2: bit - loop
	//2ms beats 36.68%
	//Time:(n * 2^n)
    public List<List<Integer>> subsets2(int[] nums) {
    	List<List<Integer>> ans = new ArrayList<>();
    	int n = nums.length;
    	for(int i = 0; i < (1 << n); i++){
    		List<Integer> cur = new ArrayList<>();
    		for(int j = 0; j < n; j++)
    			if((i & (1 << j)) != 0)
    				cur.add(nums[j]);
			ans.add(cur);
    	}
    	return ans;
    }

}