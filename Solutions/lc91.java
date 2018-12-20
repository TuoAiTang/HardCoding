import java.util.*;
class lc91 {
	//6ms beats 16.09%
	//O(n^2) -> n sub-problems * n cost (substring copy)
	//optimize to O(n) -> 3ms beats 49.76%
	private Map<Integer, Integer> memo;
    public int numDecodings(String s) {
    	if(s == null) return 0;
        memo = new HashMap<>();
        return ways(s, 0, s.length() - 1);
    }

    private int ways(String s, int l, int r){
    	if(l > r) return 1;
    	if(s.charAt(l) == '0') return 0;
    	if(l == r) return 1;
    	if(memo.containsKey(l)) return memo.get(l);

    	int w = ways(s, l + 1, r);
    	int prefix = (s.charAt(l) - '0') * 10 + (s.charAt(l + 1) - '0');
    	if(prefix >= 10 && prefix <= 26)
    		w += ways(s, l + 2, r);
    	memo.put(l, w);
    	return w;
    }
}