class lc338 {
	//3ms beats 30.49%
    public int[] countBits(int num) {
        int [] dp = new int [num + 1];
        dp[0] = 0;
        for(int i = 1; i <= num; i++)
        	dp[i] = dp[i >> 1] + (i % 2);
        return dp;
    }

    //1ms beats 99.95%
    public int[] countBits(int num) {
        int [] dp = new int [num + 1];
        dp[0] = 0;
        for(int i = 1; i <= num; i++)
        	dp[i] = dp[i >> 1] + (i & 1);
        return dp;
    }
}