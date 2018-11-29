//64ms beats 7.91%
//Time: O( mn * log(mn) )
import java.util.*;
class lc329_BottomUp {
    private class Cell{
        int val;
        int x;
        int y;
        public Cell(int val, int x, int y){
            this.val = val;
            this.x = x;
            this.y = y;
        }
    }
    public int longestIncreasingPath(int[][] matrix) {
    	int m = matrix.length;
    	if(m == 0) return 0;
    	int n = matrix[0].length;
        int [][] dp = new int [m][n];
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                dp[i][j] = 1;
        int ans = 0;

        PriorityQueue<Cell> pq = new PriorityQueue<>((c1, c2) -> c2.val - c1.val);
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                pq.add(new Cell(matrix[i][j], i, j));

        int [][] dirs = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

        while(!pq.isEmpty()){
            Cell cell = pq.remove();
            int x = cell.x;
            int y = cell.y;
            for(int [] dir : dirs){
                int nx = x + dir[0];
                int ny = y + dir[1];
                if(nx < 0 || ny < 0 || nx >= m || ny >= n || matrix[nx][ny] <= matrix[x][y])
                    continue;
                dp[x][y] = Math.max(dp[x][y], 1 + dp[nx][ny]);
            }
            ans = Math.max(ans, dp[x][y]);
        }
        return ans;                
    }
}
