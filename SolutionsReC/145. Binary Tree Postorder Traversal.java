class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        LinkedList<Integer> res = new LinkedList<>();
        Stack<TreeNode> stk = new Stack<>();
        if(root == null)
        	return res;
        stk.push(root);
        while(!stk.isEmpty()){
        	TreeNode cur = stk.pop();
        	res.addFirst(cur.val);
        	if(cur.left != null)
        		stk.push(cur.left);
        	if(cur.right != null)
        		stk.push(cur.right);
        }
        stk.push(root);
        return res;
    }

    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> res = new LinkedList<>();
        Stack<TreeNode> stk = new Stack<>();
        if(root == null)
        	return res;
        stk.push(root);
        TreeNode pLast = root, pCur = root;
        while(!stk.isEmpty()){
        	pCur = stk.peek();
        	if(pCur.left != null && pLast != pCur.right && pLast != pCur.left)
        		stk.push(pCur.left);
        	else if(pCur.right != null && pLast != pCur.right)
        		stk.push(pCur.right);
        	else{
        		stk.pop();
        		res.add(pCur.val);
        		pLast = pCur;
        	}
        }
        return res;
    }
}