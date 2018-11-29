//Time: O(m*n)
//11ms beats 59.46%
class lc329_TopDown {
    public int longestIncreasingPath(int[][] matrix) {
    	int m = matrix.length;
    	if(m == 0) return 0;
    	int n = matrix[0].length;
        int [][] dp = new int [m][n];
        int ans = 0;
        for(int i = 0; i < m; i++)
        	for(int j = 0; j < n; j++)
        		ans = Math.max(ans, dfs(i, j, matrix, dp, m, n));
    	return ans;
    }

    private int dfs(int x, int y, int [][] matrix, int [][] dp, int m, int n){  	
    	if(dp[x][y] != 0) return dp[x][y];
    	dp[x][y] = 1;
    	int [][] dirs = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    	for(int [] dir : dirs){
    		int nx = x + dir[0];
    		int ny = y + dir[1];
    		if(nx < 0 || ny < 0 || nx >= m || ny >= n || matrix[nx][ny] <= matrix[x][y])
    			continue;
    		dp[x][y] = Math.max(dp[x][y], 1 + dfs(nx, ny, matrix, dp, m, n));
    	}
    	return dp[x][y];
    }
}
