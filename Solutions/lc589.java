package tree;
import java.util.*;

public class lc589 {
//	public static List<Integer> preorder(Node root) {
//        List<Integer> res = new ArrayList<>();
//        Stack<Node> stk = new Stack<>();
//        if(root == null)
//        	return res;
//        stk.push(root);
//        while(!stk.isEmpty()) {
//        	Node p = stk.pop();
//        	res.add(p.val);
//        	int size = p.children.size();
//        	for (int i = size - 1; i >= 0; i--) 
//        		stk.push(p.children.get(i));       	
//        }
//        return res;
//    }
	
	public static List<Integer> preorder(Node root){
		List<Integer> res = new ArrayList<>();
		helper(res, root);		
		return res;
	}
	
	private static void helper(List<Integer> res, Node root) {
		if(root == null)
			return;
		res.add(root.val);
//		for (Node node : root.children)
//			helper(res, node);	
		for (int i = 0; i < root.children.size(); i++)
            helper(res, root.children.get(i));
	}

	public static void main(String[] args) {
		
	}
}

class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val,List<Node> _children) {
        val = _val;
        children = _children;
    }
};
