import java.util.*;
class lc799 {
	//Time:O(100*100)
	//Space:O(100*100)
	//12ms beats 90.18%
    public double champagneTower1(int poured, int query_row, int query_glass) {
        double [][] dp = new double[100][100];
        dp[0][0] = poured;

        for(int i = 0; i < query_row; i++)
        	for(int j = 0; j <= i; j++)
        		if(dp[i][j] > 1.0){
        			dp[i + 1][j    ] += (dp[i][j] - 1.0) / 2;
        			dp[i + 1][j + 1] += (dp[i][j] - 1.0) / 2;
        		}

        return Math.min(1.0, dp[query_row][query_glass]);
    }

    //Time:O(100*100)
	//Space:O(100)
	//14ms beats 68.3%
    public double champagneTower2(int poured, int query_row, int query_glass) {
        double [] cur = new double[query_row + 1];
        cur[0] = poured;

        for(int i = 0; i < query_row; i++){ 
        	double [] next = new double[query_row + 1]; 	
        	for(int j = 0; j <= i; j++)
        		if(cur[j] > 1.0){
        			next[j    ] += (cur[j] - 1.0) / 2;
        			next[j + 1] += (cur[j] - 1.0) / 2;
        		}
        	cur = next;
        }

        return Math.min(1.0, cur[query_glass]);
    }
}