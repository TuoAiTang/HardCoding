//	13ms beats 47.41%
//	time : O(n^3)
//	space : O(n^3)
import java.util.*;
class lc140 {
    public List<String> wordBreak(String s, List<String> wordDict) {
        Map<String, List<String>> mem = new HashMap<>();
        Set<String> dict = new HashSet<>(wordDict);
        return wordBreak(s, dict, mem);
    }

    private List<String> wordBreak(String s, Set<String> dict, Map<String, List<String>> mem){
    	List<String> ans = mem.get(s);
    	if(ans != null) return ans;
    	ans = new ArrayList<>();
    	if(dict.contains(s)){
    		ans.add(s);
    		mem.put(s, ans);
    	}

    	for(int i =  1; i < s.length(); i++){
    		String right = s.substring(i);
    		if(!dict.contains(right)) continue;
    		String left = s.substring(0, i);
    		List<String> left_ans = append(wordBreak(left, dict, mem), right);
    		for(int j = 0; j < left_ans.size(); j++)
    			ans.add(left_ans.get(j));
    	}

    	mem.put(s, ans);
    	return ans;
    }

    private List<String> append(List<String> orgList, String word){
    	List<String> newList = new ArrayList<>();
    	for(String s : orgList)
    		newList.add(s + " " + word);
    	return newList;
    }
}