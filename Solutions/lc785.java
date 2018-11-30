//9ms beats 19%
import java.util.*;
class lc785 {
    public boolean isBipartite(int[][] graph) {
        int [] colors = new int[graph.length]; //0 -> unknown; 1 -> red; -1 -> blue;
        //bfs
        Queue<Integer> q = new LinkedList<>();
        for(int i = 0; i < graph.length; i++){
            if(colors[i] != 0) continue;
            q.offer(i);
            colors[i] = 1;
            while(!q.isEmpty()){
                int cur = q.remove();
                for(int next : graph[cur]){
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