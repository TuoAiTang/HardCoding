// 4ms

// O(n^2)
int findCircleNum(int** M, int MRowSize, int MColSize) {
    int n = MRowSize;
    // int* visited = (int*)calloc(n, sizeof(int));
    int visited[200] = {0};
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
    	if(visited[i]) continue;
    	ans++;
    	dfs(M, n, i, visited);
    }
    // free(visited);
    return ans;
}

void dfs(int** M, int n, int cur, int* visited){
	if(visited[cur]) return;
	visited[cur] = 1;
	for (int i = 0; i < n; ++i)
	{
		if(M[cur][i] && !visited[i])
			dfs(M, n, i, visited);
	}
}