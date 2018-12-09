//6ms beats 95.36%
class lc80 {
    public static int removeDuplicates(int[] nums) {
    	if(nums.length < 3) return nums.length;
        int l, r;
        l = r = 2;
        for(; r < nums.length; r++)
        	if(nums[r] != nums[l - 2])
        		nums[l++] = nums[r];
        return l;
    }
    public static void main(String[] args) {
    	int [] nums = {0,0,1,1,1,1,2,3,3};
    	int l = removeDuplicates(nums);
    	for(int i = 0; i < l; i++)
    		System.out.println(nums[i]);
    }
}