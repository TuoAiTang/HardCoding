class lc678_DP {

	//DP
	//Time: O(n^3)
	//Space: O(n^2)
	//11ms beats 32.54%
    public boolean checkValidString(String s) {
    	int n = s.length();
        if(n == 0) return true;
    	char [] str = s.toCharArray();
    	boolean [][] dp = new boolean [n][n];

        //only one symbol
        for(int i = 0; i < n; i++)
            dp[i][i] = (str[i] == '*');

        for(int len = 2; len <= n; len++)
            for(int i = 0; i < n - len + 1; i++){
                int j = i + len - 1;
                //case 1
                if((str[i] == '(' || str[i] == '*') && (str[j] == ')' || str[j] == '*')){
                    if(len == 2 || dp[i + 1][j - 1]){
                        dp[i][j] = true;
                        continue;
                    }
                }

                //case 2
                for(int k = i; k < j; k++)
                    if(dp[i][k] && dp[k + 1][j]){
                        dp[i][j] = true;
                        continue;
                    }

            }

        return dp[0][n - 1];
    }
}