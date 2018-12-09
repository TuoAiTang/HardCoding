import java.util.*;
class lc139 {

	//Solution 2: DP
	//8ms beats 68.92%
	//Time: O(n^3)
	//Space: O(n)
    public static boolean wordBreak2(String s, List<String> wordDict) {
        Set<String> dict = new HashSet<>(wordDict);
        int n = s.length();
        boolean [] dp = new boolean[n + 1];
        //dp[i] -> the index from 1 to i sub-problems
        //i -> [1, n]
        //wordBreak(s.substring(0, i))
        dp[0] = true;

        //i -> the length of sub-problems
        for(int i = 1; i <= n; i++){
        	for(int j = 0; j < i; j++){
        		if(dp[j]){
        			String new_s = s.substring(j, i);	//worst O(n)
        			if(dict.contains(new_s)){
        				dp[i] = true;
        				break;
        			}
        		}
        	}
        }
        return dp[n];
    }

    //Solution 1: Memeorization Recursion
    //10ms beats 49.88%
    public static boolean wordBreak(String s, List<String> wordDict) {
        Set<String> dict = new HashSet<>(wordDict);
        Map<String, Boolean> mem = new HashMap<>();
        int n = s.length();
        return wordBreak(s, dict, mem);
    }

    private boolean wordBreak(String s, Set<String> dict, Map<String, Boolean> mem){
    	Boolean b = mem.get(s);
    	if(b != null) return b;
    	if(dict.contains(s)){
    		mem.put(s, true);
    		return true;
    	}
    	for(int j = 1; j < s.length(); j++){
    		String left = s.substring(0, j);
    		String right = s.substring(j);
    		if(dict.contains(right) && wordBreak(left, dict, mem)){
    			mem.put(s, true);
    			return true;
    		}
    	}
    	mem.put(s, false);
    	return false;
    }

    public static void main(String[] args) {
    	List<String> words = new ArrayList<>();
    	words.add("leet");
    	words.add("code");
    	String s = "leetcodecodec";
    	System.out.println(wordBreak(s, words));
    }
}