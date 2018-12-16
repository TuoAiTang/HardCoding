//2ms without memorization beats 100%
//4ms with memmorization (init outside the function) 4ms beats 68%
import java.util.*;
class lc932 {
	private static Map<Integer, int[]> mem = new HashMap<>();
    public static int[] beautifulArray(int N) {
    	int [] m = mem.get(N);
    	if(m != null)
    		return m;
        int [] ans = new int[N];
        if(N == 1)
        	ans[0] = 1;
        else{
        	int i = 0;
        	for(int odd : beautifulArray((N + 1) / 2))
        		ans[i++] = 2 * odd - 1;
        	for(int even : beautifulArray(N / 2))
        		ans[i++] = 2 * even;
        }
        mem.put(N, ans);
        return ans;
    }

    public static void main(String[] args) {
    	int [] ans = beautifulArray(100);
    	System.out.println(Arrays.toString(ans));
    }
}