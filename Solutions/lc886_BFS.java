//26ms beats 85%
//Time: O(V + E) -> buildGraph(V + E) + bfs(V + E)
//Space: O(V + E) -> store the graph (vertex, edges)
import java.util.*;
class lc886_BFS {
    public boolean possibleBipartition(int N, int[][] dislikes) {
    	//sparse graph -> construct by adjacency table
        List<List<Integer>> g = new ArrayList<>();
        for(int i = 0; i < N; i++)
        	g.add(new ArrayList<>());
        for(int [] d : dislikes){
        	g.get(d[0] - 1).add(d[1] - 1);
        	g.get(d[1] - 1).add(d[0] - 1);
        }

        int [] colors = new int[N]; //0 -> unknown; 1 -> red; -1 -> blue;

        //bfs
        Queue<Integer> q = new LinkedList<>();
        for(int i = 0; i < N; i++){
            if(colors[i] != 0) continue;
            q.offer(i);
            colors[i] = 1;
            while(!q.isEmpty()){
                int cur = q.remove();
                for(int next : g.get(cur)){
                    if(colors[next] == colors[cur]) return false;
                    if(colors[next] != 0) continue;
                    colors[next] = -colors[cur];
                    q.offer(next);
                }
            }
        }
        return true;
    }
}