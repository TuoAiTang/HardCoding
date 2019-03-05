class Solution {
    public List<Integer> postorder(Node root) {
        List<Integer> res = new ArrayList<>();
        postorder(root, res);
        return res;
    }

    public void postorder(Node root, List<Integer> li){
    	if(root != null){
    		for(Node child : root.cihldren)
    			postorder(child);
    		li.add(root.val);
    	}
    }

    public List<Integer> postorderByStack(Node root) {
        LinkedList<Integer> res = new LinkedList<>();
        Stack<Node> stk = new Stack<>();
        if(root == null)
        	return res;
        stk.push(root);
        while(!stk.isEmpty()){
        	Node cur = stk.pop();
        	res.addFirst(cur.val);
        	for(Node child : cur.children)
        		stk.push(child);
        }
        return res;
    }
}