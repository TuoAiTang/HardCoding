import java.util.*;
class lc310 {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
    	//construct adjcency table
        List<HashSet<Integer>> adj = new ArrayList<>();
        for(int i = 0; i < n; i++)
        	adj.add(new HashSet<>());
        for(int [] e : edges){
        	adj.get(e[0]).add(e[1]);
        	adj.get(e[1]).add(e[0]);     	
        }

        for(int i = 0; i < n; i++){
        	
        }

    }
}

