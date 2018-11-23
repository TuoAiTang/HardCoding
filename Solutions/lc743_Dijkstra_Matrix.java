import java.util.*;
//10ms beats 96%
class lc743_Dijkstra_Matrix {

    public int networkDelayTime(int[][] times, int N, int K) {
        //construct adjacency matrix
        int [][] g = new int[N][N];
        for(int[] e : g)
            Arrays.fill(e, -1);
        for(int[] e : times)
            g[e[0] - 1][e[1] - 1] = e[2];    

        //init dist
        int MAX_TIME = 101 * 100;
        int [] dist = new int[N];
        Arrays.fill(dist, MAX_TIME);
        dist[K - 1] = 0;

        //init collected, false default
        boolean [] collected = new boolean[N];

        int u = getMinVertex(dist, collected);
        int ans = 0;
        while(u != -1 && dist[u] != MAX_TIME){
            collected[u] = true;
            ans = Math.max(ans, dist[u]);
            for(int i = 0; i < N; i++)
                if(g[u][i] != -1 && !collected[i])
                    dist[i] = Math.min(dist[i], dist[u] + g[u][i]);
            u = getMinVertex(dist, collected);
        }
        return u == -1 ? ans : -1;       
    }

    private int getMinVertex(int [] dist, boolean [] collected){
        int min = Integer.MAX_VALUE; 
        int idx = -1;
        for(int i = 0; i < dist.length; i++){
            if(dist[i] < min && !collected[i]){
                min = dist[i];
                idx = i;
            }
        }
        return idx;
    }
}