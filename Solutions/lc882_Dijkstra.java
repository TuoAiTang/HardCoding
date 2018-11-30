import java.util.*;
//294ms beats 35.24%
class lc882_Dijkstra {
	//use dijkstra to find shortest path to every node which dist <= M
    public int reachableNodes(int[][] edges, int M, int N) {
        //construct the graph
        int [][] g = new int[N][N];
        for(int [] w : g)
        	Arrays.fill(w, -1);
        for(int [] e : edges){
        	g[e[0]][e[1]] = e[2];
        	g[e[1]][e[0]] = e[2];
        }

        int [] dist = new int[N];
        Arrays.fill(dist, M + 1);
        dist[0] = 0;
        boolean [] collected = new boolean[N];
        int ans = 0;
        //O(ElogV)
        int u = getMinVertex(dist, collected);
        while(u != -1 && dist[u] != M + 1){
        	collected[u] = true;
        	ans++;
        	for(int i = 0; i < N; i++)
        		if(g[u][i] != -1 && !collected[i] && (dist[u] + g[u][i] + 1) <= M)
        			dist[i] = Math.min(dist[i], (dist[u] + g[u][i] + 1));
    		u = getMinVertex(dist, collected);
        }
        //O(E)
        for(int [] e : edges){
        	int uv = ((M - dist[e[0]]) < 0) ? 0 : (M - dist[e[0]]);
        	int vu = ((M - dist[e[1]]) < 0) ? 0 : (M - dist[e[1]]);
        	ans += Math.min(e[2], uv + vu);
        }

        return ans;
    }

    private int getMinVertex(int [] dist, boolean [] collected){
    	int idx = -1;
    	int min = Integer.MAX_VALUE;
    	for(int i = 0; i < dist.length; i++){
    		if(!collected[i] && min > dist[i]){
    			idx = i;
    			min = dist[i];
    		}
    	}
    	return idx;
    }
}