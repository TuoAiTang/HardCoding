import java.util.*;
//2ms 70% 11 cases
class lc399_UnionSet_Version {

	public class Node{
		public String parent;
		public double ratio;
		public Node(String parent, double ratio){
			this.parent = parent;
			this.ratio = ratio;
		}

		public String toString(){
			return "parent: " + parent + " ratio: " + ratio;
		}
	}

	public class UnionSet{
		public Map<String, Node> parents = new HashMap<>();
		public Map<String, Integer> sizes = new HashMap<>();

		//a / b = ratio
		public void union(String a, String b, double ratio){
			boolean hasA = parents.containsKey(a);
			boolean hasB = parents.containsKey(b);
			if(!hasA && !hasB){
				parents.put(a, new Node(b, ratio));
				parents.put(b, new Node(b, 1.0));
				sizes.put(b, 2);
			}else if(!hasA){
				parents.put(a, new Node(b, ratio));
				sizes.put(b, sizes.getOrDefault(b, 1) + 1);
			}else if(!hasB){
				parents.put(b, new Node(a, 1.0 / ratio));
				sizes.put(a, sizes.getOrDefault(a, 1) + 1);
			}else{
				Node pa = find(a);
				Node pb = find(b);
				int sa = sizes.get(pa.parent);
				int sb = sizes.get(pb.parent);
				// merge a to b
				if(sa <= sb){
					pa.parent = pb.parent;
					pa.ratio = ratio * pb.ratio / pa.ratio;
					sizes.put(pb.parent, sizes.get(pb.parent) + 1);
				}
				//merge b to a
				else{
					pb.parent = pa.parent;
					pb.ratio = ratio * pa.ratio / pb.ratio;
					sizes.put(pa.parent, sizes.get(pa.parent) + 1);
				}
			}
		}

		public Node find(String x){
			if(!parents.containsKey(x)) return null;
			Node n = parents.get(x);
			if(!n.parent.equals(x)){
				Node p = find(n.parent);
				n.parent = p.parent;
				n.ratio *= p.ratio;
			}
			return n;
		}
		
	}
    public double[] calcEquation(String[][] equations, double[] values, String[][] queries) {
    	UnionSet us = new UnionSet();

    	for(int i = 0; i < equations.length; i++)
    		us.union(equations[i][0], equations[i][1], values[i]);

    	double [] ans = new double[queries.length];

    	for(int i = 0; i < queries.length; i++){
    		Node x = us.find(queries[i][0]);
    		Node y = us.find(queries[i][1]);
    		if(x == null || y == null || !x.parent.equals(y.parent))
    			ans[i] = -1.0;
			else
				ans[i] = x.ratio / y.ratio;
		}

		return ans;
    }

}