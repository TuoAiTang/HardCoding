//8ms beats 16.22
//O(n)
import java.util.*;
class lc863_Grpah_BFS {
	public class TreeNode {
    	int val;
    	TreeNode left;
    	TreeNode right;
    	TreeNode(int x) { val = x; }
	}
    public List<Integer> distanceK(TreeNode root, TreeNode target, int K) {
        List<Integer> ans = new ArrayList<>();

    	if(root == null) return ans;

        Map<Integer, List<Integer>> g = new HashMap<>();
        buildGraph(null, root, g);

        Queue<Integer> q = new LinkedList<>();
        int [] visited = new int [501];
        q.offer(target.val);
        int k = 0;
        //O(n)
        while(!q.isEmpty() && k <= K){
        	int size = q.size();
        	while(size-- > 0){
        		int cur = q.remove();
        		if(visited[cur] == 1) continue;
        		visited[cur] = 1;
        		if(k == K)
        			ans.add(cur);
        		else{
        			for(int next : g.get(cur))
        				q.offer(next);
        		}
        	}
        	k++;
        }
        return ans;
    }
    //O(n)
    private void buildGraph(TreeNode parent, TreeNode child, Map<Integer, List<Integer>> g){
    	if(parent != null){
    		if(g.get(parent.val) == null)
    			g.put(parent.val, new ArrayList<>());
    		if(g.get(child) == null)
    			g.put(child.val, new ArrayList<>());
    		g.get(parent.val).add(child.val);
    		g.get(child.val).add(parent.val);
    	}
    	if(child.left != null)
    		buildGraph(child, child.left, g);
    	if(child.right != null)
    		buildGraph(child, child.right, g);
    }
}