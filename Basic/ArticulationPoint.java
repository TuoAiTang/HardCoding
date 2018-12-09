import java.util.*;
class ArticulationPoint{
	private static Map<Integer, List<Integer>> graph = new HashMap<>();
	private static int [] low;
	private static boolean [] visited;
	private static int [] num;
	private static int [] parents;
	private static int counter = 1;
	private static List<Integer> points = new ArrayList<>();

	/*	Use adjacency map to represents an undirected graph.
	**	Use two steps to find Art-Point.
	**
	**	First: Use preorder to assign num of each node.
	**
	**	Second: Use postorder to caculate the low of eachn node, by three rules.
	**	while checking it whether it is art-point (v: low[v.child] >= low[v]). 
	**
	**	Note: the three rules to caculate the low value.
	**	1.num[v]
	**	2.Lowest num[w] of back-edge (v, w)
	**	3.Lowest low[w] of foward-edge (v, w)
	**	Choose the minimum value above to represents the low value of v.
	*/

	static void buildGraph(){
		for(int i = 0; i < 7; i++)
			graph.put(i, new ArrayList<>());
		int [][] edges = {{1, 2}, {1, 4}, {2, 3}, 
						  {3, 4}, {3, 7}, {4, 5},
						  {4, 6}, {5, 6}};
	  	for(int [] e : edges){
	  		graph.get(e[0] - 1).add(e[1] - 1);
	  		graph.get(e[1] - 1).add(e[0] - 1);
	  	}

	  	low = new int[7];
	  	parents = new int[7];
	  	Arrays.fill(parents, -1);
	  	num = new int[7];
	  	visited = new boolean[7];

	  	System.out.println(graph);
	}

	static void FindArt(){
		int num_of_vertex = graph.keySet().size();
		int root = 0;
		AssignNum(root);
		for(int i = 0; i < num.length; i++)
			System.out.println("num[" + i + "]:" + num[i]);
		if(counter <= num_of_vertex){
			System.out.println("The graph is not connected!");
			return;
		}

		//check the root
		int child = 0;
		for(int p : parents){
			if(p == root)
				child++;
			if(child > 1)
				break;
		}
		if(child > 1) points.add(root);
		System.out.println("child:" + child);

		AssignLow(root);
		for(int i = 0; i < low.length; i++)
			System.out.println("low[" + i + "]:" + low[i]);

	}

	static void AssignNum(int v){
		num[v] = counter++;
		visited[v] = true;
		for(int next : graph.get(v)){
			if(!visited[next]){
				parents[next] = v;
				AssignNum(next);
			}
		}
	}

	static void AssignLow(int v){
		low[v] = num[v];	//rule 1
		for(int w : graph.get(v)){
			if(num[w] > num[v])	//foward edge
			{
				AssignLow(w);
				if(low[w] >= num[v])
					points.add(v);
				low[v] = Math.min(low[v], low[w]);	//rule 3
			}
			else if(parents[v] != w)	//back-edge
				low[v] = Math.min(low[v], num[w]);	//rule 2

		}
	}	

	public static void main(String[] args) {
		buildGraph();
		FindArt();
		System.out.println(points);
	}
}