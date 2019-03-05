class Solution {
    public int maxDepth(Node root) {
        if(root == null) return 0;
        int maxDepth = 0;
        for(Node n : root.children)
        	maxDepth = Math.max(maxDepth, maxDepth(n));
        return maxDepth + 1;
    }
}