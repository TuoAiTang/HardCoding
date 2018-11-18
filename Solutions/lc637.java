package tree;
import java.util.*;
public class lc637 {
	public static List<Double> averageOfLevels(TreeNode root) {
        List<Double> res = new ArrayList<Double>();
        if(root == null)
        	return res;
        Queue<TreeNode> que = new LinkedList<>();
        que.offer(root);
        while(!que.isEmpty()) {        	
        	int size = que.size();
        	long sum = 0;
        	int n = size;
        	while(n-- > 0) {
        		TreeNode cur = que.remove();
        		sum += cur.val;
        		if(cur.left != null)
        			que.offer(cur.left);
        		if(cur.right != null)
        			que.offer(cur.right);
        		
        	}
        	res.add((double)sum / size);       	
        }       
        return res;
    }
	
	public static void main(String[] args) {
		TreeNode t = TreeNode.createTree(5);
		TreeNode.printTree(t);
		List<Double> res = averageOfLevels(t);
		System.out.println(res);
	}
}
