import java.util.*;
// 3ms 67.16%
class lc685 {
    public int[] findRedundantDirectedConnection(int[][] edges) {
        int [] parents = new int[edges.length + 1];
        int [] roots = new int[edges.length + 1];
        int [] sizes = new int[edges.length + 1];

        int [] ans1 = new int[2];
        int [] ans2 = new int[2];

        for(int i = 0; i < edges.length; i ++){
        	int u = edges[i][0];
        	int v = edges[i][1];

        	//two duplicate parents
        	if(parents[v] > 0){
        		ans1[0] = parents[v]; ans1[1] = v;
        		//later edge
        		ans2[0] = edges[i][0]; ans2[1] = edges[i][1];

        		//delete the later edge
        		edges[i][0] = edges[i][1] = -1;
        	}

        	parents[v] = u;
        }

     	for(int i = 0; i < edges.length; i ++){
     		int u = edges[i][0];
     		int v = edges[i][1];

     		if(u == -1 && v == -1) continue;

     		if(roots[u] == 0) roots[u] = u;
     		if(roots[v] == 0) roots[v] = v;

     		int pu = find(u, roots);
     		int pv = find(v, roots);

     		//cycle caused by ans1 or edges[i]
     		if(pu == pv)
     			return (ans1[0] == 0) ? edges[i] : ans1;
     		//swap
     		if(sizes[pu] > sizes[pv]){
     			int tmp = pu; pu = pv; pv = tmp;
     		}

     		roots[pu] = pv;
     		sizes[pv] += sizes[pu];
     	}

     	return (ans2[0] == 0) ? null : ans2;
    }

    private int find(int id, int [] parents){
    	if(parents[id] != id)
    		parents[id] = find(parents[id], parents);
    	return parents[id];
    }
}