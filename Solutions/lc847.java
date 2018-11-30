//24ms beats 48.48%
//Time: O(n * 2^n)
//Space: O(n * 2^n)
import java.util.*;
class lc847 {
    public int shortestPathLength(int[][] graph) {
        int n = graph.length;
        int FINAL_STATE = (1 << n) - 1;
        Queue<int []> q = new LinkedList<>();
        int [][] visited = new int [n][1 << n];
        for(int i = 0; i < n; i++)
        	q.offer(new int [] {i, 1 << i});
        int steps = 0;
        while(!q.isEmpty()){
        	int size = q.size();
        	while(size-- > 0){
        		int [] p = q.remove();
	        	int node = p[0];
	        	int state = p[1];
	        	if(state == FINAL_STATE) return steps;
	        	if(visited[node][state] == 1) continue;
	        	visited[node][state] = 1;
	        	for(int next : graph[node])
	        		q.offer(new int [] {next, state | (1 << next)});
        	}
    		steps++;    	
        }
        return -1;
    }
}
