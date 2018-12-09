//Solution 1.DP
//Time: O(mn)
//Space: O(mn)
//Runtime: 0ms beats 100%
int uniquePaths(int m, int n) {
    int** dp = (int**)malloc((m + 1) * sizeof(int*));
    for(int i = 0; i < m + 1; i++){
    	dp[i] = (int*)malloc((n + 1) * sizeof(int));
    	memset(dp[i], 0, (n + 1) * sizeof(int));
    }
    dp[1][1] = 1;
    for(int i = 1; i <= m; i++){
    	for(int j = 1; j <= n; j++){
    		if(i == 1 && j == 1) continue;
    		dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    	}
    }
    int ans = dp[m][n];
    for(int i = 0; i < m + 1; i ++)
    	free(dp[i]);
    free(dp);
    return ans;
}


//Solution 2.Top-Down Recursion with memorization.
//Time: O(mn)
//Space: O(mn)
//Runtime: 0ms beats 100%
int uniquePaths(int m, int n) {
    int** dp = (int**)malloc((m + 1) * sizeof(int*));
    for(int i = 0; i < m + 1; i++){
    	dp[i] = (int*)malloc((n + 1) * sizeof(int));
    	memset(dp[i], -1, (n + 1) * sizeof(int));
    }
    int ans = dfs(dp, m, n);
    for(int i = 0; i < m + 1; i ++)
    	free(dp[i]);
    free(dp);
    return ans;
}

int dfs(int** dp, int m, int n){
	if(m == 0 || n == 0) return 0;
	if(m == 1 && n == 1) return 1;
	if(dp[m][n] != -1) return dp[m][n];
	dp[m][n] = dfs(dp, m - 1, n) + dfs(dp, m, n - 1);
	return dp[m][n];
}


