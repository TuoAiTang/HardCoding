//9ms beats 19% ->BFS
//4ms beats 95% -> DFS
import java.util.*;
class lc785 {
    public boolean isBipartite(int[][] graph) {
        int [] colors = new int[graph.length]; //0 -> unknown; 1 -> red; -1 -> blue;
        for(int i = 0; i < graph.length; i++)
        	if(colors[i] == 0 && !dfs(i, 1, graph, colors))
        		return false;

        //bfs
        // Queue<Integer> q = new LinkedList<>();
        // for(int i = 0; i < graph.length; i++){
        //     if(colors[i] != 0) continue;
        //     q.offer(i);
        //     colors[i] = 1;
        //     while(!q.isEmpty()){
        //         int cur = q.remove();
        //         for(int next : graph[cur]){
        //             if(colors[next] == colors[cur]) return false;
        //             if(colors[next] != 0) continue;
        //             colors[next] = -colors[cur];
        //             q.offer(next);
        //         }
        //     }
        // }
        return true;
    }

    private boolean dfs(int cur, int color, int [][] g, int [] colors){
    	colors[cur] = color;
    	for(int next : g[cur]){
    		if(colors[next] == color) return false;
    		if(colors[next] == 0 && !dfs(next, -color, g, colors))
    			return false;
    	}
    	return true;
    }
}