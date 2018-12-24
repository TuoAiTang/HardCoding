class lc64 {
	//Solution 1: DP
	//Time: O(mn)
	//Space: O(1)
	//6ms beats 51.32%
    public int minPathSum1(int[][] grid) {
    	int m = grid.length;
    	if(m == 0) return 0;
    	int n = grid[0].length;
        for(int i = 0; i < m; i++)
        	for(int j = 0; j < n; j++){
        		if(i == 0 && j == 0) continue;
        		if(i == 0) grid[i][j] += grid[i][j - 1];
        		else if(j == 0) grid[i][j] += grid[i - 1][j];
        		else grid[i][j] += Math.min(grid[i - 1][j], grid[i][j - 1]);
        	}

        return grid[m - 1][n - 1];
    }

    //Solution 1: MR
	//Time: O(mn)
	//Space: O(mn)
	//6ms beats 51.32%
    public int minPathSum2(int[][] grid) {
    	int m = grid.length;
    	if(m == 0) return 0;
    	int n = grid[0].length;
    	int [][] memo = new int [m][n];
    	return minSum(grid, memo, m - 1, n - 1);
    }

    private int minSum(int [][] grid, int [][] memo, int i, int j){
    	if(i < 0 || j < 0) return Integer.MAX_VALUE;
    	if(i == 0 && j == 0) return grid[i][j];
    	if(memo[i][j] > 0) return memo[i][j];
    	int ans = grid[i][j] + Math.min(minSum(grid, memo, i - 1, j), minSum(grid, memo, i, j - 1));
    	return memo[i][j] = ans;
    }

}