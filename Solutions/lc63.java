//0ms beats 100%
import java.util.*;
class lc63 {
	private int [][] dp;
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
       	int m = obstacleGrid.length;
       	if(m == 0) return 0;
       	int n = obstacleGrid[0].length;
       	dp = new int[m + 1][n + 1];
       	//-1 means not solved
       	for(int [] d: dp)
       		Arrays.fill(d, -1);
       	dp[1][1] = 1 - obstacleGrid[0][0];

       	return paths(m, n, obstacleGrid);
    }

    private int paths(int m, int n, int [][] o){
    	if(m <= 0 || n <= 0) return 0;
    	if(dp[m][n] != -1) return dp[m][n];

    	if(o[m - 1][n - 1] == 1)
    		return dp[m][n] = 0;
    	dp[m][n] = paths(m - 1, n, o) + paths(m, n - 1, o);
    	return dp[m][n];
    }
}