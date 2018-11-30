//O(n)
//2ms beats 79.82%
import java.util.*;
class lc863_Recursion {
	public class TreeNode {
    	int val;
    	TreeNode left;
    	TreeNode right;
    	TreeNode(int x) { val = x; }
	}
 	public List<Integer> distanceK(TreeNode root, TreeNode target, int K) {
 		List<Integer> ans = new ArrayList<>();
 		dis(root, target, K, ans);
 		return ans;
 	}

 	private int dis(TreeNode root, TreeNode target, int K, List<Integr> ans){
 		if(root == null) return -1;
 		if(root == target){
 			collect(ans, root, K);
 			return 0;
 		}

 		int l = dis(root.left, target, K, ans);
 		int r = dis(root.right, target, K, ans);
 		//target in left subtree
 		if(l >= 0){
 			if(l == K - 1) ans.add(root.val);
 			collect(ans, root.right, K - l - 2);
 			return l + 1;
 		}
 		// target in right subtree
 		if(r >= 0){
 			if(r == K - 1) ans.add(root.val);
 			collect(ans, root.left, K - r - 2);
 			return r + 1;
 		}
 		//target not in root
 		return -1;
 	}

 	private void collect(List<Integer> ans, TreeNode root, int d){
 		if(root == null || d < 0)
 			return;
 		if(d == 0)
 			ans.add(root.val);
 		collect(ans, root.left, d - 1);
 		collect(ans, root.right, d - 1);
 	}
}