class Solution {
    public TreeNode increasingBST(TreeNode root) {
        TreeNode dummy = new TreeNode(-1);
        TreeNode [] prev = { dummy };
        inorder(prev, root);
        return dummy.right;
    }
   	public void inorder(TreeNode [] prev, TreeNode root){
   		if(root == null) return;
   		inorder(prev, root.left);
   		prev[0].right = root;
   		prev[0] = root;
   		root.left = null;
   		inorder(prev, root.right);
   	}	
}