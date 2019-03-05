class Solution {
    public List<Double> averageOfLevels(TreeNode root) {
        List<Double> res = new ArrayList<>();
        if(root == null) return res;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        while(!q.isEmpty()){
        	int size = q.size();
        	int devide = size;
        	double sum = 0.0;
        	while(size-- > 0){
        		TreeNode cur = q.poll();
        		sum += cur.val;
        		if(cur.left != null) 
        			q.offer(cur.left);
        		if(cur.right != null)
        			q.offer(cur.right);
        	}
        	res.add(sum / devide);
        }
        return res;
    }
}