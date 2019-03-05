class Solution {
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        LinkedList<List<Integer>> res = new LinkedList<>();
        if(root == null) return res;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        while(!q.isEmpty()){
        	int size = q.size();
        	List<Integer> level = new ArrayList<>();
        	while(size-- > 0){
        		TreeNode cur = q.poll();
        		level.add(cur.val);
        		if(cur.left != null)
        			q.offer(cur.left);
        		if(cur.right != null)
        			q.offer(cur.right);
        	}
        	res.addFirst(level);
        }
        return res;
    }
}