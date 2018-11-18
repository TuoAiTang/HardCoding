package tree;
import java.util.*;
public class lc101 {
//	public static boolean isSymmetric(TreeNode root) {
//		if(root == null) return true;
//        Queue<TreeNode> q = new LinkedList<>();
//        q.offer(root.left);
//        q.offer(root.right);
//        while(!q.isEmpty()) {
//        	TreeNode t1 = q.remove();
//        	TreeNode t2 = q.remove();
//        	if(t1 == null && t2 == null) continue;
//        	if(t1 == null || t2 == null) return false;
//        	if(t1.val != t2.val) return false;
//        	q.add(t1.left);
//        	q.add(t2.right);
//        	q.add(t1.right);
//        	q.add(t2.left);
//        }
//        return true;       
//    }
	public boolean isSymmetric(TreeNode root) {
		if(root == null) return true;
		return isMirror(root.left, root.right);    
    }
	
	public boolean isMirror(TreeNode t1, TreeNode t2) {
		if(t1 == null && t2 == null) return true;
		if(t1 == null || t2 == null) return false;
		return ((t1.val == t2.val) && isMirror(t1.left, t2.right)
				&& isMirror(t1.right, t2.left));
	}
	
	
	
	public static void main(String[] args) {
		TreeNode t = TreeNode.createTree(8);
		TreeNode.printTree(t);
		System.out.println(1 << 5);
	}
	
}
