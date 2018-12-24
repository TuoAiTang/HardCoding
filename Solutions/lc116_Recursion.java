import java.util.*;
public class lc116_Recursion {
    //Solution 2: dfs (recursion)
    //Time:O(n)
    //Space: O(logn) --> total 2^(logn) = O(n), but it return when reaches the leaf node
    //0ms beats 100%

    /*TreeLinkNode next pointer point to null default*/
    public void connect(TreeLinkNode root) {
    	if(root == null) return;
        if(root.left != null) root.left.next = root.right;
        if(root.right != null) root.right.next = root.next == null ? null : root.next.left;
    	connect(root.left);
        connect(root.right);
    }


}
