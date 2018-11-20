import java.util.*;
//O(n^2)
//261ms 5.58%
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


        for(int i = 0; i < numCourses; i++){
        	int [] visited = new int[numCourses];
            if(hasCycle(i, i, visited)) return false;
        }

        return true;
    }

    private boolean hasCycle(int start, int cur, int [] visited){
        if(start == cur && visited[start] == 1) return true;
        if(!graph.containsKey(cur)) return false;
        for(Integer next : graph.get(cur)){
            if(visited[next] == 1) continue;
            visited[next] = 1;
            if(hasCycle(start, next, visited)) return true;
        }
        return false;
    }
    
}