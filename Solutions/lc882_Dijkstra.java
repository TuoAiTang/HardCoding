import java.util.*;
class lc882_Dijkstra {
	//use dijkstra to find max hp for every node
    public int reachableNodes(int[][] edges, int M, int N) {
        //construct the graph
        int [][] g = new int[N][N];
        for(int [] w : g)
        	Arrays.fill(w, -1);
        for(int i = 0; i < N; i++)
        	g[i][i] = 0;
        for(int [] e : edges){
        	g[e[0]][e[1]] = e[2];
        	g[e[1]][e[0]] = e[2];
        }

        PriorityQueue<int []> pq = new PriorityQueue<>((a, b) -> b[1] - a[1]);	//int [] -> {node, hp}
        int [] HP = new int [N];
        Arrays.fill(HP, -1);
        int ans = 0;

        pq.offer(new int [] {0, M});

        while(!pq.isEmpty()){
        	int [] cur = pq.remove();
        	int node = cur[0];
        	int hp = cur[1];
        	if(HP[node] != -1) continue;
        	HP[node] = hp;
        	ans++;
        	for(int i = 0; i < N; i++){
        		if(g[node][i] != -1){
        			int nnode = i;
        			int nhp = hp - g[node][i] - 1 ;
        			if(HP[i] != -1 || nhp < 0)
        				continue;
        			pq.offer(new int [] {i, nhp});
        		}
        	}
        }

        for(int [] e : edges){
        	int uv = (HP[e[0]] == -1) ? 0 : HP[e[0]];
        	int vu = (HP[e[1]] == -1) ? 0 : HP[e[1]];
        	ans += Math.min(e[2], uv + vu);
        }

        return ans;
    }
}