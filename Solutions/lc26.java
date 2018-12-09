//6ms beats 97.88%
class lc26 {
    public static int removeDuplicates(int[] nums) {
    	if(nums.length < 2) return nums.length;
        int l, r;
        l = r = 1;
        for(; r < nums.length; r++){
        	if(nums[r] != nums[l - 1])
        		nums[l++] = nums[r];
        }
        return l;
    }

    public static void main(String[] args) {
    	int [] nums = {0,0,1,1,1,2,2,3,3,4};
    	int l = removeDuplicates(nums);
    	for(int i = 0; i < l; i++)
    		System.out.println(nums[i]);
    }
}