import java.util.*;
//2ms 70% 11 cases
class lc399 {
    public double[] calcEquation(String[][] equations, double[] values, String[][] queries) {
    	//construct the graph, g.get(A).get(B) = k, means k = A / B 
        Map<String, Map<String, Double>> graph = new HashMap<>();
        for(int i = 0; i < equations.length; i ++){
        	String A = equations[i][0];
        	String B = equations[i][1];
        	double k = values[i];

        	if(!graph.containsKey(A))
        		graph.put(A, new HashMap<>());

        	if(!graph.containsKey(B))
        		graph.put(B, new HashMap<>());

        	graph.get(A).put(B, k);
        	graph.get(B).put(A, 1.0 / k);
        } 

        List<Double> res = new ArrayList<>();
        for(String [] q : queries){
        	String x = q[0];
        	String y = q[1];
        	if(!graph.containsKey(x) || !graph.containsKey(y)){
        		res.add(-1.0);
        		continue;
        	}
        	Set<String> visited = new HashSet<>();
        	res.add(divide(x, y, graph, visited));
        }

        double [] ans = new double[res.size()];
        for(int i = 0; i < ans.length; i++)
        	ans[i] = res.get(i);

        return ans;
    }

    private double divide(String x, String y, Map<String, Map<String, Double>> graph, Set<String> visited){
    	if(x == y) return 1.0;
    	visited.add(x);
    	for(String z : graph.get(x).keySet()){
    		if(visited.contains(z)) continue;
    		double d = divide(z, y, graph, visited);
    		if(d > 0)
    			return graph.get(x).get(z) * d;
    	}

    	return -1.0;
    }
}