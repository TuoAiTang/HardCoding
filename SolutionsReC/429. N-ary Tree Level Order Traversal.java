class Solution {
    public List<List<Integer>> levelOrder(Node root) {
    	List<List<Integer>> res = new ArrayList<>();
    	if(root == null) return res;
        Queue<Node> q = new LinkedList<>();
        q.offer(root);
        while(!q.isEmpty()){
        	int size = q.size();
        	List<Integer> level = new ArrayList<>();
        	while(size -- > 0){
        		Node cur = q.remove();
        		level.add(cur.val);
        		for(Node child : cur.cihldren)
        			q.offer(child);
        	}
        	res.add(level);
        }
        return res;
    }
}