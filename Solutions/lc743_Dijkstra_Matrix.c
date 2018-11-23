//To Tang, i love you.
//Author: TuoAiTang --> https://tuoaitang.github.io 

int min(int a, int b){
    return a < b ? a : b;
}

int max(int a, int b){
    return a > b ? a : b;
}

int getMinVertex(int* dist, int* collected, int N){
    int min = INT_MAX; 
    int idx = -1;
    for(int i = 0; i < N; i++){
        if(dist[i] < min && !collected[i]){
            min = dist[i];
            idx = i;
        }
    }
    return idx;
}

int networkDelayTime(int** times, int timesRowSize, int timesColSize, int N, int K) {
    //construct adjacency matrix
    int g[N][N];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            g[i][j] = -1;
    for(int i = 0; i < timesRowSize; i++)
        g[times[i][0] - 1][times[i][1] - 1] = times[i][2];    

    //init dist
    int MAX_TIME = 101 * 100;
    int dist[N];
    for(int i = 0; i < N; i++)
        dist[i] = MAX_TIME;
    dist[K - 1] = 0;

    //init collected, false default
    int collected[N];
    for(int i = 0; i < N; i++)
        collected[i] = 0;

    int u = getMinVertex(dist, collected, N);
    int ans = 0;
    while(u != -1 && dist[u] != MAX_TIME){
        collected[u] = 1;
        ans = max(ans, dist[u]);
        for(int i = 0; i < N; i++)
            if(g[u][i] != -1 && !collected[i])
                dist[i] = min(dist[i], dist[u] + g[u][i]);
        u = getMinVertex(dist, collected, N);
    }
    return (u == -1) ? ans : -1;       
}