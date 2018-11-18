package hashtable;
import java.util.*;
public class lc349 {
	public static int[] intersection(int[] nums1, int[] nums2) {
        List<Integer> res = new ArrayList<>();
        int i = 0;
        Set<Integer> hs = new HashSet<>();
        for(int num : nums1)
            hs.add(num);
        for(int num : nums2){
            if(hs.contains(num)){
                res.add(num);
                hs.remove(num);
            }
        }
        int [] ans = new int[res.size()];
        for(int j = ans.length - 1; j >= 0; j--)
        	ans[j] = res.get(j);
        return ans;
    }
	public static void main(String[] args) {
		int [] a = {1, 2, 5};
		int [] b = {2, 3, 1};
		int [] c = intersection(a, b);
		for (int i = 0; i < c.length; i++) {
			System.out.println(c[i]);
		}
	}
}
