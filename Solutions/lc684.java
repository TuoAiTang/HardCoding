import java.util.*;

//16ms
class lc684{
	public int[] findRedundantConnection(int[][] edges) {
		//Adjacency list to reprents a graph
		//Construct the graph, while checking the circle 
        Map<Integer, List<Integer>> graph = new HashMap<>();
        for(int i = 0; i < edges.length; i ++){
        	int u = edges[i][0];
        	int v = edges[i][1];

        	Set<Integer> visited = new HashSet<>();
        	if(hasPath(graph, u, v, visited))
        		return edges[i];

        	//no path between in the graph
        	//add path to each other, for graph is non-directed

        	if(graph.get(u) == null)
        		graph.put(u, new ArrayList<>());
        	if(graph.get(v) == null)
        		graph.put(v, new ArrayList<>());

        	graph.get(u).add(v);
        	graph.get(v).add(u);
        }
        return null;
    }

    //Time : n + (n - 1) + (n - 2) + ... + 3 + 2 + 1 = O(n^2)
    //Dfs
    private Boolean hasPath(Map<Integer, List<Integer>> graph, int u, int v, Set<Integer> visited){
    	if(u == v) return true;

    	visited.add(u);

    	List<Integer> u_neighbors = graph.get(u);
    	List<Integer> v_neighbors = graph.get(v);
    	if(u_neighbors == null || v_neighbors == null)
    		return false;

    	for(Integer neighbor : u_neighbors){
    		if(visited.contains(neighbor)) continue;
    		visited.add(neighbor);
    		if(hasPath(graph, neighbor, v, visited))
    			return true;
    	}

    	return false;
    }
}