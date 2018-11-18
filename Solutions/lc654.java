package tree;
import java.util.*;

public class lc654 {
	public TreeNode constructMaximumBinaryTree(int[] nums) {
        return makeBT(nums, 0, nums.length);
    }

	private TreeNode makeBT(int[] nums, int begin, int end) {
		if(begin > end) return null;
		int maxIndex = getMaxIndex(nums, begin, end);
		TreeNode root = new TreeNode(nums[maxIndex]);
		root.left = makeBT(nums, begin, maxIndex - 1);
		root.right = makeBT(nums, maxIndex + 1, end);				
		return root;
	}

	private int getMaxIndex(int[] nums, int begin, int end) {
		int maxIndex = begin;
		for (int i = begin + 1; i <= end; i++) {
			if(nums[i] > nums[maxIndex])
				maxIndex = i;			
		}
		return maxIndex;
	}
}
