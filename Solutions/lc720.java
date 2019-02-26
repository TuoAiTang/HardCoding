import java.util.*;
class lc720 {
	//Solution 1 : HashSet-BruteForce + Prunning
	//Time: O(n * l^2) l, the length of each word
	//Space: O(n) n, the number of words
	//Runntime: 18ms beats 68.41%
    public String longestWord1(String[] words) {
        Set<String> dict = new HashSet<>();
        for(String w : words)
        	dict.add(w);

        int max_len = 0;
        String ans = "";
        for(String w : words){
        	if(w.length() < max_len) continue;
        	if(w.length() == max_len && w.compareTo(ans) >= 0) continue;
        	StringBuilder sb = new StringBuilder();
        	boolean flag = true;
        	//O(l^2) = O(1) + O(2) + ... + O(l)
        	for(int i = 0; i < w.length(); i++){
        		sb.append(w.charAt(i));
        		if(!dict.contains(sb.toString())) {
        			flag = false;
        			break;
        		}
        	}
        	if(flag){
        		max_len = w.length();
        		ans = w;
        	}       	
        }

        return ans;
    }


    //Solution 2 : Trie + Prunning
	//Time: O(n) l, the length of each word
	//Space: O(26n) n, the number of words
	//Runntime: 9ms beats 97.39%
    public String longestWord2(String[] words) {
    	Trie t = new Trie();
    	for(String w : words)
    		t.insert(w);
    	int max_len = 0;
    	String ans = "";
    	for(String w : words){
        	if(w.length() < max_len) continue;
        	if(w.length() == max_len && w.compareTo(ans) >= 0) continue;
        	if(t.hasAllPrefixes(w)){
        		max_len = w.length();
        		ans = w;
        	}        	
        }
    	return ans;
    }
}