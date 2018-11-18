package tree;
import java.util.*;

public class lc590 {
//	public static List<Integer> postorder(Node root) {
//		LinkedList<Integer> res = new LinkedList<>();
//		Stack<Node> stk = new Stack<>();
//		if(root == null)
//			return res;
//		stk.push(root);
//		while(!stk.isEmpty()) {
//			Node nod = stk.pop();
//			res.addFirst(nod.val);
//			for (Node node : nod.children)
//				stk.push(node);
//		}		
//		return res;
//    }
	
	public static List<Integer> postorder(Node root) {
		LinkedList<Integer> res = new LinkedList<>();
		helper(res, root);
		return res;
	}
	
	
	private static void helper(LinkedList<Integer> res, Node root) {
		if(root == null)
			return;
		for (Node node : root.children) {
			helper(res, node);
		}
		res.add(root.val);	
	}


	public static void main(String[] args) {
		
	}

}
