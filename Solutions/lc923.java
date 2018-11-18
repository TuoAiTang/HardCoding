package hashtable;
import java.util.*;
public class lc923 {
	public int threeSumMulti(int[] A, int target) {
        long res = 0;
        Map<Integer, Integer> hm = new HashMap<>();
        for(int i : A) {
        	Integer count = hm.get(i);
        	if(count == null)
        		hm.put(i,  1);
        	else
        		hm.put(i,  count + 1);
        }
        //assume that i <= j <= k
        for(int i = 0; i <= target / 3; i++) {
        	for(int j = i; j <= target / 2; j++) {
        		int k = target - i - j;
        		if(k < j) continue;
        		if(i == j && j == k) {
        			long count_i = hm.get(i) == null ? 0 : hm.get(i);
        			res += count_i * (count_i - 1) * (count_i - 2) / 6;
        		}else if(i == j) {
        			long count_i = hm.get(i) == null ? 0 : hm.get(i);
        			long count_k = hm.get(k) == null ? 0 : hm.get(k);       			
        			res += count_i * (count_i - 1) / 2 * count_k;
        		}else if(j == k) {
        			long count_i = hm.get(i) == null ? 0 : hm.get(i);
        			long count_j = hm.get(j) == null ? 0 : hm.get(j);
        			res += count_j * (count_j - 1) / 2 * count_i;
        		}else {
        			long count_i = hm.get(i) == null ? 0 : hm.get(i);
        			long count_j = hm.get(j) == null ? 0 : hm.get(j);
        			long count_k = hm.get(k) == null ? 0 : hm.get(k);
        			res += count_i * count_j * count_k;
        		}
        			
        	}
        }
        
        int ans = (int)(res % (Math.pow(10, 9) + 7));
        return ans;
    }
}
