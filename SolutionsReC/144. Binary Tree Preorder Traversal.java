class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        Stack<TreeNode> stk = new Stack<>();
        if(root == null)
        	return res;
        stk.push(root);
        while(!stk.isEmpty()){
        	TreeNode cur = stk.pop();
        	res.add(cur.val);
        	if(cur.right != null)
        		stk.push(cur.right);
        	if(cur.left != null)
        		stk.push(cur.left);
        }
        return res;
    }

    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        preorder(root, res);
        return res;
    }

    public void preorder(TreeNode root, List<Integer> li){
    	if(root != null){
    		li.add(root.val);
    		preorder(root.left);
    		preorder(root.right);
    	}
    }
}