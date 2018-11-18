package tree;
import java.util.*;
public class lc655 {
	public static List<List<String>> printTreeToList(TreeNode root) {
        List<List<String>> res = new ArrayList<>();
        int height = getHeight(root);
        int width = (1 << height) - 1;
        String [][] ans = new String[height][width];
        for (String[] strings : ans) {
        	Arrays.fill(strings, " ");
        }
        fillList(root, ans, 0, width - 1, 0);
        for (String[] strings : ans) {
			res.add(Arrays.asList(strings));
		}
        return res;
    }
	private static void fillList(TreeNode t, String [][] ans, int l, int r, int level) {
		if(t == null) return;
		int mid = (l +  r) / 2;
		ans[level][mid] = "" + t.val;
		fillList(t.left, ans, l, mid - 1, level + 1);
		fillList(t.right, ans, mid + 1, r, level + 1);
	}
	private static int getHeight(TreeNode t) {
		if(t == null) return 0;
		return Math.max(getHeight(t.left), getHeight(t.right)) + 1;
	}
	
	public static void main(String[] args) {
		TreeNode t = TreeNode.createTree(8);
		TreeNode.printTree(t);
		
		TreeNode.printLikeTree(t);
	}
}
