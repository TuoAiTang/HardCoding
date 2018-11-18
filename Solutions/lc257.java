package tree;
import java.util.*;
public class lc257 {
	 public static List<String> binaryTreePaths(TreeNode root) {
        Stack<TreeNode> stk = new Stack<>();
        List<String> res = new LinkedList<String>();
        Stack<String> str_stk = new Stack<>();
        if(root == null)
        	return res;
        stk.push(root);
        str_stk.push("");
        while(!stk.isEmpty()) {
        	TreeNode t = stk.pop();
        	String path = str_stk.pop() + t.val;
        	if(t.right == null && t.left == null)
        		res.add(path);
        	else {
        		path += "->";
        		
            	if(t.right != null) {
            		str_stk.push(path);
            		stk.push(t.right);
            	}
            	if(t.left != null) {
            		str_stk.push(path);
            		stk.push(t.left);
            	} 
        	}	    	
        }      
        return res;		 
	 }
	 
	 public static void main(String[] args) {
		 TreeNode t = TreeNode.createTree(12);
		TreeNode.printTree(t);
		List<String> res = binaryTreePaths(t);
		System.out.println(res);
	}
	 
	 
}
//tmp = stk.peek();
//while(stk.peek().left != null) {       		
//	stk.push(stk.peek().left);
//	str_stk.push(str_stk.peek() + "->" + stk.peek().val);
//}
//while(!stk.isEmpty()) {
//	tmp = stk.pop();       		
//	if(tmp.right != null) {
//		stk.push(tmp.right);
//		if(tmp.right.right == null && tmp.right.left == null)
//			str_stk.pop();
//		str_stk.push(str_stk.peek() + "->" + tmp.right.val);
//		break;
//	}
//	res.add(str_stk.pop()); 