import java.util.*;
class TreeLinkNode {
    int val;
    TreeLinkNode left, right, next;
    TreeLinkNode(int x) { val = x; }
}
//Solution 1 : bfs (level traversal)
//Time: O(n)
//Space: O(n)
//3ms beats 13.90%
public class lc116 {
    public void connect(TreeLinkNode root) {
    	if(root == null) return;
        Queue<TreeLinkNode> q = new LinkedList<>();
        q.add(root);
        while(!q.isEmpty()){
        	int size = q.size();
        	while(size-- > 1){
        		TreeLinkNode n = q.remove();
        		n.next = q.peek();
        		if(n.left != null)
        			q.add(n.left);
        		if(n.right != null)
        			q.add(n.right);
        	}
        	TreeLinkNode end = q.remove();
        	end.next = null;
        	if(end.left != null) q.add(end.left);
        	if(end.right != null) q.add(end.right);
    	}
    }
}


