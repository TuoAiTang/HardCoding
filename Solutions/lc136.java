class lc136 {
	//XOR
	//1ms beats 72.14%
    public int singleNumber(int[] nums) {
        int x = 0;
        for(int n : nums)
        	x ^= n;
        return x;
    }
}