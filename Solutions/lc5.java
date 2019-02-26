import java.util.*;
class lc5 {
	//if the string is palindrome
	private Map<String, Boolean> memo;
    public String longestPalindrome(String s) {
        memo = new HashMap<>();
        dfs(s);
        String ans = "";
        for(String key : memo.keySet())
            if(memo.get(key) && ans.length() < key.length())
                ans = key;
        return ans;
    }

    private boolean dfs(String s){
    	if(s.length() < 2) return true;
    	if(memo.containsKey(s)) return memo.get(s);
    	int mid = s.length() / 2;
    	if(s.length() % 2 == 0){
    		if(s.charAt(mid - 1) != s.charAt(mid)){
    			memo.put(s, false);
    			return false;
    		}
    		String left = s.substring(0, mid - 1);
    		String right = s.substring(mid + 1);
    		if(!dfs(String.join("", left, right))){
    			memo.put(s, false);
    			return false;
    		}
    		else{
    			memo.put(s, true);
    			return true;
    		}
    	}else{
    		String left = s.substring(0, mid);
    		String right = s.substring(mid + 1);
            if(!dfs(String.join("", left, right))){
                memo.put(s, false);
                return false;
            }
            else{
                memo.put(s, true);
                return true;
            }
    	}
    }
}