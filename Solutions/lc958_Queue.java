import java.util.*;
class lc958_Queue {
	//Solution 2: level traversal
	//Time: O(n)
	//Space: O(n)
	//Runntime: 7ms beats 31.68%
	/*
		if the tree is complete, once you meet the null, 
		you reach the very end of the tree,
		after that, the queue is all null nodes.

		if you find one node null, but after it,
		one non-null node occurs, 
		means it is not a complete tree.

	*/
    public boolean isCompleteTree(TreeNode root) {
    	if(root == null) return true;
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        while(!q.isEmpty() && q.peek() != null){
        	TreeNode t = q.remove();
        	q.add(t.left);
        	q.add(t.right);       	
        }

        while(!q.isEmpty())
        	if(q.remove() != null)
        		return false;
    	return true;
    }
}