import java.util.*;
//O(n)
//14ms beats 63.9 
class lc207_Topological_Sort {
	private Map<Integer, List<Integer>> graph = new HashMap<>();

    public boolean canFinish(int numCourses, int[][] prerequisites) {
    	//construct the adjacency table        
        for(int i = 0; i < prerequisites.length; i++){
        	int cur = prerequisites[i][0];
        	int pre = prerequisites[i][1];
        	if(!graph.containsKey(cur))
        		graph.put(cur, new ArrayList<>());
        	graph.get(cur).add(pre);
        }

        int [] v = new int[numCourses];

        for(int i = 0; i < numCourses; i++){
        	if(dfs(i, v)) return false;
        }

        return true;
    }


    private boolean dfs(int cur, int [] v){
    	if(v[cur] == 1) return true;	//1, visiting, cycle

    	if(v[cur] == 2) return false;	//2, visited, no cycle

    	v[cur] = 1;

    	//no prerequisites
    	if(!graph.containsKey(cur)){
    		v[cur] = 2;
    		return false;
    	}

    	for(Integer pre : graph.get(cur))
    		if(dfs(pre, v)) return true;

    	v[cur] = 2;
    	return false;
    }
}