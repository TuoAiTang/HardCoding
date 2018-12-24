/*	
	Full tree(strict complete tree)
	1. nodes : 2^h - 1
	2. left and right, full
	3. null -> full
	4. left.height == right.height

	Complete tree
	1. isCompleteTree(root.left)
	2. isCompleteTree(root.right)
	3. 0 <= left.height - right.leight <= 1
	4. if left.height == right.height : left is full
	5. if left.height == right.height + 1: right is full

*/

//Solution 1: recursion
//Time: O(n)
//Space: O(h)
//Runntime: 4ms beats 99.94%
class lc958 {
	class Pair{
		boolean is_full;	//strict full tree
		int height;				//height == -1, not complete tree; height != -1, complete tree's height;
		Pair(boolean is_f, int h) {is_full = is_f;  height = h; }
	}
    public boolean isCompleteTree(TreeNode root) {
        return helper(root).height != -1;	//check complete tree
    }

    private Pair helper(TreeNode t){
    	if(t == null) return new Pair(true, 0);
    	Pair left = helper(t.left);
    	Pair right = helper(t.right);
    	int lh = left.height;
    	int rh = right.height;
    	int delta_h = lh - rh;
    	if(lh < 0 || rh < 0) return new Pair(false, -1);
    	if(delta_h < 0 || delta_h > 1) return new Pair(false, -1);
    	if(delta_h == 1 && !right.is_full) return new Pair(false, -1);
    	if(delta_h == 0 && !left.is_full) return new Pair(false, -1);
    	int height = Math.max(lh, rh) + 1;
    	return new Pair(delta_h == 0 ? left.is_full && right.is_full: false, height);
    }
}

