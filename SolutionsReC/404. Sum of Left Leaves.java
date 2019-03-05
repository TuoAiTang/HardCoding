class Solution {
    public int sumOfLeftLeaves(TreeNode root) {
    	return helper(root, false);
    }

    public int helper(TreeNode root, boolean is_left){
    	if(root == null) return 0;
    	if(is_left && root.left == null && root.right == null)
    		return root.val;
    	return helper(root.left, true) + helper(root.right, false);
    }
}