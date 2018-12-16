//74ms beats 50.36%
class lc463 {
    public int islandPerimeter(int[][] grid) {
        if(grid == null) return 0;
        int m = grid.length;
        int n = grid[0].length;

        int area = 0;
        int conn = 0;

        for(int i = 0; i < m; i++)
        	for(int j = 0; j < n; j++)
        		if(grid[i][j] == 1){
        			++area;
        			//count the half conn from left col and up row
        			if(i > 0 && grid[i - 1][j] == 1) ++conn;
        			if(j > 0 && grid[i][j - 1] == 1) ++conn; 
        		}

		return area * 4 - conn * 2;
    }
}