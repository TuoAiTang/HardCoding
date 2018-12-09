import java.util.*;
class MinimumSpanningTree{
	
	/*	Assume the graph is given by adjacency matrices.
	**  Here are two greedy methods: Prim and KrusKal,
	**  To caculate the minimum sum of the tree.
	**	For Prim:
	** 		Time: O(V^2)
	**		Space: O(V) -> store the dist array
	**	For KrusKal:
	**		Time: O(ElogE)
	**		Space: O(V + E)
	**	We can draw a concusion that:
	**		Prim better for dense graph;
	**		Kruskal better for sparse graph;
	*/

	//it seems like an un-directed grah, dosen't matter
	//for this graph, answer is 16
	public static int [][] graph = {{0, 2, 4, 1, -1, -1, -1}, 	//v1
									{2, 0, -1, 3, 10, -1, -1},	//v2
									{4, -1, 0, 2, -1, 5, -1},	//v3
									{1, 3, 2, 0, 7, 8, 4},		//v4
									{-1, 10, -1, 7, 0, -1, 6},	//v5
									{-1, -1, 5, 8, -1, 0, 1},	//v6
									{-1, -1, -1, 4, 6, 1, 0}}; 	//v7

	//prepared for Kruskal
	//u -> start vertex; v -> destiny vertex; w -> weights;								
	static class Edge{
		int u, v, w;
		Edge(int u_, int v_, int w_) {u = u_; v = v_; w = w_;}
	}

	public static int Prim(int [][] g){
		int sum = 0;
		int n = g.length;
		//init the distance to vertex 0
		//tree spans from vertex 0
		int [] dist = new int[n];
		for(int i = 0; i < n; i++)
			dist[i] = (g[0][i] == -1) ? Integer.MAX_VALUE : g[0][i];

		int collected = 1;
		int u = getMinVertex(dist);
		while(u != -1 && collected < n){
			sum += dist[u];
			dist[u] = 0;	//add to tree
			collected++;
			for(int i = 0; i < n; i++){
				if(g[u][i] != -1 && dist[i] != 0) //neibors of u, which has not been added yet
					dist[i] = Math.min(dist[i], g[u][i]);
			}
			u = getMinVertex(dist);
		}

		if(collected < n)
			return -1;	//the graph is not all connected

		return sum;
	}	

	private static int getMinVertex(int [] dist){
		int idx = -1;
		int sum = 0;
		int min = Integer.MAX_VALUE;
		for(int i = 0; i < dist.length; i++){
			if(min > dist[i] && dist[i] != 0){
				idx = i;
				min = dist[i];
			}
		}	
		return idx;
	}

	public static int Kruskal(int [][] g){
		int n = g.length;
		int sum = 0;
		//construct the min heap, sorted by edge weights
		PriorityQueue<Edge> pq = new PriorityQueue<>((a, b) -> a.w - b.w);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(g[i][j] != -1 && i != j){
					pq.offer(new Edge(i, j, g[i][j]));
				}
			}
		}

		//union set member
		int [] parents = new int[n];
		int [] sizes = new int[n];
		//init
		for(int i = 0; i < n; i++)
			parents[i] = i;				

		int edges = 0;
		while(!pq.isEmpty() && edges < n - 1){
			Edge e = pq.remove();
			//success union indicates that e dosen't construct loops
			//failure union, continue
			if(union(e.u, e.v, parents, sizes)){
				sum += e.w;
				edges++;
			}
		}
		if(edges < n - 1)
			return -1;
		return sum;
	}

	private static int find(int u, int [] parents){
		if(parents[u] != u)
			parents[u] = find(parents[u], parents);
		return parents[u];
	}

	private static boolean union(int i, int j, int [] parents, int sizes[]){		
		int pi = find(i, parents);
		int pj = find(j, parents);

		if(pi == pj) return false;	//has already been unioned 
		if(sizes[pi] > sizes[pj]){
			parents[pj] = pi;
			sizes[pi] += sizes[pj];
		}
		else{
			parents[pi] = pj;
			parents[pj] += sizes[pi];
		}
		return true;
	}		

	public static void main(String[] args) {
		System.out.println(Prim(graph));		//16
		System.out.println(Kruskal(graph));		//16
	}	 
}
