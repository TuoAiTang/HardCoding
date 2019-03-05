class Solution {
    public boolean findTarget(TreeNode root, int k) {
        List<Integer> li = new ArrayList<>();
        inorder(root, li);
        int l = 0, r = li.size - 1;
        while(l < r){
        	int sum = li.get(l) + li.get(r);
        	if(sum == k)
        		return true;
        	if(sum < k)
        		l++;
        	else
        		r--;
        }
        return false;
    }

    public void inorder(TreeNode root, List<Integer> li){
    	if(root != null){
    		inorder(root.left, li);
    		li.add(root.val);
    		inorder(root.right, li);
    	}
    }
}


class Solution2 {
	TreeNode orgRoot;
    public boolean findTarget(TreeNode root, int k) {
        orgRoot = root;
        return dfs(root, k);
    }

    public boolean dfs(TreeNode root, int k){
    	if(root == null) return false;
    	if(find(orgRoot, k - root.val, root)) return true;
    	return dfs(root.left, k) || dfs(root.right, k);
    }

    public boolean find(TreeNode root, int val, TreeNode ref){
    	if(root == null) return false;
    	if(root.val == val && root != ref)
    		return true;
    	if(root.val < val)
    		return find(root.right, val, ref);
    	else
    		return find(root.left, val, ref);
    }
}