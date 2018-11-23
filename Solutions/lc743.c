//32ms bellman-ford beats 15.79
int networkDelayTime(int** times, int timesRowSize, int timesColSize, int N, int K) {
    int MAX_TIME = 101 * 100;
    int dist[100];
    for(int i = 0; i < 100; i ++)
    	dist[i] = MAX_TIME;

    dist[K - 1] = 0;
    for(int i = 1; i < N; i++){
    	for(int j = 0; j < timesRowSize; j++){
    		int u = times[j][0] - 1;
    		int v = times[j][1] - 1;
    		int w = times[j][2];

    		dist[v] = min(dist[v], dist[u] + w);
    	}
    }
    int max_time = getMax(dist, N);
    return (max_time == MAX_TIME) ? -1 : max_time;
}

int min(int a, int b){
	return a < b ? a : b;
}

int max(int a, int b){
	return a > b ? a : b;
}

int getMax(int* arr, int size){
	int max_val = arr[0];
	for(int i = 1; i < size; i++)
		max_val = max(max_val, arr[i]);
	return max_val;
}