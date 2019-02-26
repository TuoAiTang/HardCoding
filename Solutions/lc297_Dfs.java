public class lc297_Dfs {

	//14ms beats 60%
	//Recursion Solution
    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        StringBuilder sb = new StringBuilder();
        serialize(root, sb);
        return sb.toString();
    }

    private void serialize(TreeNode root, StringBuilder sb){
    	if(root == null) {
    		sb.append("# ");
    		return;
    	}
    	sb.append(root.val + " ");
    	serialize(root.left, sb);
    	serialize(root.right, sb);
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
    	String [] str = data.split(" ");
        return deserialize(str, new int[] {0});
    }

    private TreeNode deserialize(String [] str, int [] cur){
    	if(str[cur[0]].equals("#")){
    		cur[0] ++;
    		return null;
    	}
    	TreeNode root = new TreeNode(Integer.parseInt(str[cur[0]]));
    	cur[0]++;
    	root.left = deserialize(str, cur);
    	root.right = deserialize(str, cur);
    	return root;
    }
}