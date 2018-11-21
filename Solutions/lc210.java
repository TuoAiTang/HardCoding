import java.util.*;
//O(V + E) ~ O(n)
//16ms beats 50.04
//Topologogical 
class lc210 {
	private Map<Integer, List<Integer>> graph = new HashMap<>();
    public int[] findOrder(int numCourses, int[][] prerequisites) {
    	List<Integer> ans = new ArrayList<>();
        //construct the adjacency table        
        for(int i = 0; i < prerequisites.length; i++){
        	int cur = prerequisites[i][0];
        	int pre = prerequisites[i][1];
        	if(!graph.containsKey(pre))
        		graph.put(pre, new ArrayList<>());
        	graph.get(pre).add(cur);
        }

        int [] v = new int[numCourses];

        for(int i = 0; i < numCourses; i++){
        	if(dfs(i, v, ans)) {
        		return (new int[0]);
        	}
        }

        int [] res = new int[ans.size()];
        for(int i = ans.size() - 1; i >= 0; i--)
        	res[ans.size() - 1 - i] = ans.get(i);
    	
        return res;
    }

    private boolean dfs(int cur, int [] v, List<Integer> ans){
    	if(v[cur] == 1) return true;
    	if(v[cur] == 2) return false;

    	if(!graph.containsKey(cur)){
    		v[cur] = 2;
    		ans.add(cur);
    		return false;
    	}

    	v[cur] = 1;
    	for(Integer next : graph.get(cur)){
    		if(dfs(next, v, ans)) return true;
    	}

    	v[cur] = 2;
    	ans.add(cur);
    	return false;
    }
}