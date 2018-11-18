package tree;
import java.util.*;
public class lc606 {
	public static String tree2str(TreeNode t) {
        if(t == null)
        	return "";
        if(t.left == null && t.right == null)
        	return t.val + "";
        if(t.right == null)
        	return t.val + "(" + tree2str(t.left) + ")";
        return t.val + "(" + tree2str(t.left) + ")(" + tree2str(t.right)+ ")"; 
    }
	
//	public static String tree2str(TreeNode t) {
//        if(t == null)
//        	return "";
//        Stack<TreeNode> stk = new Stack<>();
//        stk.push(t);
//        StringBuilder sb = new StringBuilder();
//        while(!stk.isEmpty()) {
//        	TreeNode cur = stk.pop();
//        	if(cur.left == null  && cur.right == null) {
//        		sb.append(cur.val);
//        		continue;
//        	}
//        	if(cur.right == null) {
//        		sb.append(cur.val + )
//        	}

	
	public static void main(String[] args) {
		TreeNode t = TreeNode.createTree(5);
		TreeNode.printTree(t);
		System.out.println(tree2str(t));
	}
}
