//34ms beats 3.53%
import java.util.*;
class lc785 {
    public boolean isBipartite(int[][] graph) {
        //sparse graph -> construct by adjacency table
        List<List<Integer>> g = new ArrayList<>();
        for(int i = 0; i < graph.length; i++)
        	g.add(new ArrayList<>());
        for(int i = 0; i < graph.length; i++){
        	for(int j : graph[i]){
        		g.get(i).add(j);
        		g.get(j).add(i);
        	}
        }

        int [] colors = new int[graph.length]; //0 -> unknown; 1 -> red; -1 -> blue;

        //bfs
        Queue<Integer> q = new LinkedList<>();
        for(int i = 0; i < graph.length; i++){
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