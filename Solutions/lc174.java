/*	Time: O(mn)
**	Space: O(mn) -> O(n)
** 	Runtime: 7ms beats 14.15% -> 6ms beats 25.71%
** 	
**	dp[i][j] -> the lowest hp before the knights step into 
**	the dungeon[i][j].
**
**
**
*/
import java.util.*;
class lc174 {
    public int calculateMinimumHP(int[][] dungeon) {
        int m = dungeon.length;
        int n = dungeon[0].length ;
        int [][] dp = new int[m + 1][n + 1];
        for(int [] d: dp)
        	Arrays.fill(d, Integer.MAX_VALUE);
        dp[m - 1][n] = dp[m][n - 1] = 1;
        for(int i = m - 1; i >= 0; i--){
        	for(int j = n - 1; j >= 0; j--){
        		dp[i][j] = Math.max(1, Math.min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
        	}
        }
        return dp[0][0];
    }

    public int calculateMinimumHP2(int[][] dungeon) {
        int m = dungeon.length;
        int n = dungeon[0].length ;
        int [] dp = new int[n + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[n - 1] = 1;
        //dp[j] -> the lowest hp before the knights step into j column
        for(int i = m - 1; i >= 0; i--){
        	for(int j = n - 1; j >= 0; j--){
        		dp[j] = Math.max(1, Math.min(dp[j], dp[j + 1]) - dungeon[i][j]);
        	}
        }
        return dp[0];
    }
}