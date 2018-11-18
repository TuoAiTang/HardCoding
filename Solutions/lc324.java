package sort;
import java.util.*;
public class lc324 {
	public static void wiggleSort(int[] nums) {
        Arrays.sort(nums);
        for(int i = 1; i + 1 < nums.length; i += 2) {
        	int tmp = nums[i];
        	nums[i] = nums[i+1];
        	nums[i+1] = tmp;
        }
    }
	public static void main(String[] args) {
		int [] a = {1,2,3,4,5};
		wiggleSort(a);
		for (int i = 0; i < a.length; i++) {
			System.out.println(a[i]);
		}
	}
}
