//move element: 8ms beats 19%
//move pointer: 6ms beats 48%
class lc27 {
    // public int removeElement(int[] nums, int val) {
    //     int ans = nums.length;
    //     for(int i = 0; i < ans; i++){
    //     	if(nums[i] == val){
    //     		for(int j = i; j < ans - 1; j++){
    //     			nums[j] = nums[j + 1];
    //     			ans--;
    //     		}
    //     	}
    // 	}
    // 	return ans;
    // }
    public int removeElement(int[] nums, int val) {
        int l, r;
        l = r = 0;
        for(; r < nums.length; r++)
        	if(nums[r] != val)
        		nums[l++] = nums[r];
    	return l;
    }
}