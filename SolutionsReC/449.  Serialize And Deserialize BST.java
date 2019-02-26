public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        StringBuilder sb = new StringBuilder();
        serialize(root, sb);
        return sb.toString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        int [] cur = new int [1];
        cur[0] = 0;
        String [] dataArray = data.split(" ");
        return deserialize(dataArray, cur);
    }

    public TreeNode deserialize(String [] data, int [] cur){
    	String s = data[cur[0]];
    	cur[0] ++;
    	if(s.equals("#"))
    		return null;    
    	TreeNode t = new TreeNode(Integer.parseInt(s));
    	t.left = deserialize(data, cur);
    	t.right = deserialize(data, cur);
        return t;
    }

    public void serialize(TreeNode root, StringBuilder sb){
    	if(root == null) {
    		sb.append("# ");
    		return;
    	}
    	sb.append(root.val + " ");
    	serialize(root.left, sb);
    	serialize(root.right, sb);
    }
}