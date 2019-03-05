class Solution {
    public TreeNode trimBST(TreeNode root, int L, int R) {
        if(root == null) return;
        if(root.val > R){
        	root.right = null;
        	return trimBST(root, L, R);
        }
        if(root.val < L){
        	root.left = null;
        	return trimBST(root, L, R);
        }
        root.left = trimBST(root.left, L, R);
        root.right = trimBST(root.right, L, R);
        return root;
    }
}