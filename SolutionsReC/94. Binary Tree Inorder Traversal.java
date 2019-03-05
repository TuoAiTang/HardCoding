class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> res = new LinkedList<>();
        Stack<TreeNode> stk = new Stack<>();
        if(root == null)
        	return res;
        stk.push(root);
        while(!stk.isEmpty()){
        	while(stk.peek().left != null)
        		stk.push(stk.peek().left);
        	while(!stk.isEmpty()){
        		TreeNode p = stk.pop();
        		res.add(p.val);
        		if(p.right != null){
        			stk.push(p.right);
        			break;
        		}
        	}
        }
        return res;
    }
}