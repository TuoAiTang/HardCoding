//22ms 50.41
//Time: O(V + E)
//Space: O(V + E)
import java.util.*;
class lc802 {
	int UNKOWN = 0;
	int VISITING = 1;
	int SAFE = 2;
	int UNSAFE = 3;
    public List<Integer> eventualSafeNodes(int[][] graph) {
    	List<Integer> ans = new ArrayList<>();

    	//init unknown default
        int [] states = new int[graph.length];
        for(int i = 0; i < graph.length; i++){
        	if(dfs(graph, i, states) == SAFE)
        		ans.add(i);
        }
        return ans;
    }
    //memory recursion
    private int dfs(int [][] g, int i, int [] states){
    	if(states[i] == VISITING)
    		return states[i] = UNSAFE;
    	if(states[i] != UNKOWN)
    		return states[i];
    	states[i] = VISITING;
    	for(int next : g[i]){
    		if(dfs(g, next, states) == UNSAFE)
    			return states[i] = UNSAFE;
    	}
    	return states[i] = SAFE;
    }
}