import java.util.*;
//17ms beats 47.77%
//O(n)
class lc817_graph_cc {
    public int numComponents(ListNode head, int[] G) {
    	if(head == null) return 0;
        int [] set = new int[10000];
        for(int val : G)
        	set[val] = 1;
        //construct the graph
        Map<Integer, List<Integer>> map = new HashMap<>();
        int u = head.val;
        while(head.next != null){
        	head = head.next;
        	int v = head.val;
        	if(set[u] != 0 && set[v] != 0){
        		if(map.get(u) == null)
        			map.put(u, new ArrayList<>());
                if(map.get(v) == null)
                    map.put(v, new ArrayList<>());

        		//undirected map
        		map.get(u).add(v);
        		map.get(v).add(u);
        	}
        	u = v;
        }

        int ans = 0;
        int [] visited = new int[10000];
        for(int val : G){
        	if(visited[val] == 1) continue;
        	ans++;
        	dfs(map, val, visited);
        }
        return ans;
    }
    //O(E) = O(2V)
    private void dfs(Map<Integer, List<Integer>> map, int u, int [] visited){
    	if(visited[u] == 1) return;
    	visited[u] = 1;
    	if(map.get(u) == null) return;
    	for(int v : map.get(u)){
    		dfs(map, v, visited);
    	}
    }
}