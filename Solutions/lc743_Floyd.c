//28ms 22.73%
int min(int a, int b){
    return a < b ? a : b;
}

int max(int a, int b){
    return a > b ? a : b;
}

int networkDelayTime(int** times, int timesRowSize, int timesColSize, int N, int K) {
    //construct adjacency matrix
    int MAX_TIME = 101 * 100;
    int g[N][N];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            g[i][j] = 101 * 100;
    for (int i = 0; i < N; ++i)
        g[i][i] = 0;
    for(int i = 0; i < timesRowSize; i++)
        g[times[i][0] - 1][times[i][1] - 1] = times[i][2];

    for(int k = 0; k < N; k++)
        for(int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);  
    int ans = -1;
    for(int i = 0; i < N; i++)
        ans = max(ans, g[K - 1][i]);
    return (ans == MAX_TIME) ? -1 : ans;     
}