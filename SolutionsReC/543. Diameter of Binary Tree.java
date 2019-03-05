class Solution {
	int ans = 0;
    public int diameterOfBinaryTree(TreeNode root) {
        oneSideDiameter(root);
        return ans;
    }

    public int oneSideDiameter(TreeNode root){
    	if(root == null) return 0;
        int left = oneSideDiameter(root.left);
        ans = left + oneSideDiameter(root.right) + 2;
        return left + 1;
    }
}