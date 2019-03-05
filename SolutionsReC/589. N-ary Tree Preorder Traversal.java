class Solution {

    public List<Integer> preorder(Node root) {
    	List<Integer> li = new ArrayList<>();
    	preorder(root, li);
    	return li;
    }

    public void preorder(Node root, List<Integer> li){
    	if(root == null)
    		return;
    	li.add(root.val);
    	for(Node n : root.children)
    		preorder(n, li);
    }

    public List<Integer> preorderByStack(Node root){
    	List<Integer> li = new ArrayList<>();
    	if(root == null)
    		return li;
    	Stack<Node> stk = new Stack<>();
    	stk.push(root);
    	while(!stk.isEmpty()){
    		Node cur = stk.pop();
    		li.add(cur.val);
    		int size = cur.children.size();
    		for(int i = size - 1; i >= 0; i --)
    			stk.push(cur.children.get(i));
    	}
    	return li;
    }
}