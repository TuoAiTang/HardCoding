//1.DP
//Time: O(n)
//Space: O(n) -> O(1)

//1.1
int climbStairs(int n) {
	//Space: O(n)
    int* dp = (int*)calloc(n + 1, sizeof(int));
    dp[0] = dp[1] = 1;
    for(int i = 2; i <= n; i++)
    	dp[i] = dp[i - 1] + dp[i - 2];
    int ans = dp[n];
    free(dp);
    return ans;
}

//1.2
int climbStairs(int n) {
	//Space: O(1)
	if(n <= 1) return 1;
	int dp1 = 1;
	int dp2 = 1;
	int ans;
    for(int i = 2; i <= n; i++){
    	ans = dp1 + dp2;
    	dp2 = dp1;
    	dp1 = ans;
    }
    return ans;
}


//2.Top-Down Recursion with memorization.
//Time: O(n)
//Space: O(n)
//Runtime: 0ms beats 100%
int climbStairs(int n) {
    int* res = (int*)calloc(n + 1, sizeof(int));
    int ans = dfs(res, n);
    free(res);
    return ans;
}

int dfs(int* res, int n){
	if(n <= 1) return 1;
	if(res[n]) return res[n];
	res[n] = dfs(res, n - 1) + dfs(res, n - 2);
	return res[n];
}



//3. Brute Force
//Time: O(2^n) - TLE
//Space: O(n) ->recursion depth
int climbStairs(int n) {
    if(n <= 1) return 1;
    return climbStairs(n - 1) + climbStairs(n - 2);
}