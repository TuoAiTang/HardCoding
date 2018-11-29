import java.util.*;
//O(2 * n^2)
//32ms 38.93% --> 14ms 92.62% after change global variables to function args
class lc827 {
    public int largestIsland(int[][] grid) {
        int m = grid.length;
        if(m == 0)
        	return 0;
        int n = grid[0].length;
        int ans = 0;
        int id = 1;
        //find cc and calculate areas
        int [] areas = new int[252];	//map <id, area>; 250 CCs at most;
        for(int i = 0; i < m; i++){
        	for(int j = 0; j < n; j++){
        		if(grid[i][j] == 1)
        			areas[++id] = getArea(i, j, id, grid, m, n);
        		ans = Math.max(ans, areas[id]);
        	}
        }
        //enum to make largest area       
        for(int i = 0; i < m; i++){
        	for(int j = 0; j < n; j++){
        		if(grid[i][j] == 0){
        			int area = 1;
        			Set<Integer> set = new HashSet<>();
        			set.add(getId(i - 1, j, grid, m, n));
        			set.add(getId(i + 1, j, grid, m, n));
        			set.add(getId(i, j - 1, grid, m, n));
        			set.add(getId(i, j + 1, grid, m, n));
        			Iterator<Integer> it = set.iterator();
        			while(it.hasNext())
        				area += areas[it.next()];
        			ans = Math.max(ans, area);
        		}
        	}
        }
        return ans;
    }
    private int getId(int x, int y, int [][] g, int m, int n){
    	if(x < 0 || y < 0 || x > m - 1 || y > n - 1)
    		return 0;
    	return g[x][y];
    }
    private int getArea(int x, int y, int id, int [][] g, int m, int n){
    	if(x < 0 || y < 0 || x > m - 1 || y > n - 1 || g[x][y] != 1)
    		return 0;
    	g[x][y] = id;
    	return 1 + getArea(x - 1, y, id, g, m, n) + getArea(x + 1, y, id, g, m, n)
    			 + getArea(x, y - 1, id, g, m, n) + getArea(x, y + 1, id, g, m, n);
    }
}