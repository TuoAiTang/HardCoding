import java.util.*;
//O(2 * n^2)
//32ms 38.93%
class lc827 {
	private int m;
	private int n;
	private int id = 1;	//connected components id
	private int [][] g;	
    public int largestIsland(int[][] grid) {
        m = grid.length;
        if(m == 0)
        	return 0;
        n = grid[0].length;
        g = grid;
        int ans = 0;
        //find cc and calculate areas
        int [] areas = new int[252];	//map <id, area>; 250 CCs at most;
        for(int i = 0; i < m; i++){
        	for(int j = 0; j < n; j++){
        		if(grid[i][j] == 1)
        			areas[++id] = getArea(i, j);
        		ans = Math.max(ans, areas[id]);
        	}
        }
        //enum to make largest area
        
        for(int i = 0; i < m; i++){
        	for(int j = 0; j < n; j++){
        		if(g[i][j] == 0){
        			int area = 1;
        			Set<Integer> set = new HashSet<>();
        			set.add(getId(i - 1, j));
        			set.add(getId(i + 1, j));
        			set.add(getId(i, j - 1));
        			set.add(getId(i, j + 1));
        			Iterator<Integer> it = set.iterator();
        			while(it.hasNext())
        				area += areas[it.next()];
        			ans = Math.max(ans, area);
        		}
        	}
        }
        return ans;
    }
    private int getId(int x, int y){
    	if(x < 0 || y < 0 || x > m - 1 || y > n - 1)
    		return 0;
    	return g[x][y];
    }
    private int getArea(int x, int y){
    	if(x < 0 || y < 0 || x > m - 1 || y > n - 1 || g[x][y] != 1)
    		return 0;
    	g[x][y] = id;
    	return 1 + getArea(x - 1, y) + getArea(x + 1, y)
    			 + getArea(x, y - 1) + getArea(x, y + 1);
    }
}