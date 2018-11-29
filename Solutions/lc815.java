import java.util.*;
//Time: O(m * n) m, buses number; n, stops each bus can reach;
//88ms 51.54%
class lc815 {
    public int numBusesToDestination(int[][] routes, int S, int T) {
    	//start = destination
    	if(S == T) return 0;
        //construct the graph
        //<stop, buses> buses (all passed stop)
    	Map<Integer, List<Integer>> graph = new HashMap<>();
    	for(int i = 0; i < routes.length; i++)
    		for(int stop : routes[i]){
    			if(graph.get(stop) == null)
    				graph.put(stop, new ArrayList<>());
    			graph.get(stop).add(i);
    		}
		Queue<Integer> q = new LinkedList<>();
		q.offer(S);

		int ans = 0;
		int [] bus_take = new int [routes.length];
		while(!q.isEmpty()){
			ans++;
			int size = q.size();
			while(size -- > 0){
				int stop = q.remove();
				if(!graph.containsKey(stop))
					continue;
				for(int bus : graph.get(stop)){
					if(bus_take[bus] == 1) continue;
					bus_take[bus] = 1;
					for(int stop_ : routes[bus]){
						if(stop_ == T) return ans;
						q.offer(stop_);
					}
				}
			}
		}

		return -1;
    }
}
