int numIslands(char** grid, int gridRowSize, int gridColSize) {
    int m = gridRowSize;
    int n = gridColSize;
    int ans = 0;
    for (int i = 0; i < m; ++i)
    {
    	for (int j = 0; j < n; ++j)
    	{
    		if(grid[i][j] == '1'){
    			ans++;
    			dfs(grid, m, n, i, j);
    		}
    	}
    }
    return ans;
}	

//destroy the islands by dfs
void dfs(char** grid, int m, int n, int x, int y){
	if(x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == '0')
		return;
	grid[x][y] = '0';
	dfs(grid, m, n, x + 1, y);
	dfs(grid, m, n, x - 1, y);
	dfs(grid, m, n, x, y + 1);
	dfs(grid, m, n, x, y - 1);
}	