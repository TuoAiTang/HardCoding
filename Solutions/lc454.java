package hashtable;
import java.util.*;
public class lc454 {
	 public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {
		 int res = 0;
		 Map<Integer, Integer> ht = new HashMap<>();
	     for (int i : A) {
			for(int j : B) {
				Integer count = ht.get(i + j);
				if(count == null)
					ht.put(i + j, 1);
				else
					ht.put(i + j, count + 1);
			}
		}
	    for(int i : C) {
	    	for(int j : D) {
	    		Integer count = ht.get(-i - j);
	    		res += count != null ? count : 0;
	    	}
	    }
	    return res;
     }
}
