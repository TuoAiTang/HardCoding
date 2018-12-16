import java.util.*;
class lc688 {
	//Solution 1: DP
	//Time: O(k * n ^ 2)
	//Space: O(k * n ^ 2) -> O(n^2)
    public double knightProbability(int N, int K, int r, int c) {
        double [][][] dp = new double[K + 1][N][N];
        dp[0][r][c] = 1.0;

        int [][] dir = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2},
    					{2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

        for(int k = 1; k <= K; k++)
        	for(int i = 0; i < N; i++)
        		for(int j = 0; j < N; j++){
        			if(dp[k - 1][i][j] == 0) continue;
        			for(int d = 0; d < 8;d++){
        				int x = i + dir[d][0];
        				int y = j + dir[d][1];
        				if(x < 0 || y < 0 || x >= N || y >= N) continue;
        				dp[k][x][y] += dp[k - 1][i][j];
        			}
        		}

		double total = 0;
		for(int i = 0; i < N; i++)
    		for(int j = 0; j < N; j++)
    			total += dp[K][i][j];
		return total / Math.pow(8, K);
    }
}