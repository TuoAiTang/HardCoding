public class lc116_Iteration {
	//Solution 3: Iteration (similar with level traversal)
	//Time: O(n)
	//Space: O(1)
	//1ms beats 40.42%
    public void connect(TreeLinkNode root) {
    	/*TreeLinkNode next pointer point to null default*/
        while(root != null){
        	TreeLinkNode cur = root;
        	while(cur != null){
        		if(cur.left != null) cur.left.next = cur.right;
        		if(cur.right != null && cur.next != null) cur.right.next = cur.next.left;
        		cur = cur.next;
        	}
        	root = root.left;
        } 	
    }
}