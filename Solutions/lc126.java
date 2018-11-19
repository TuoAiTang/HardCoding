import java.util.*;

//190ms beats 39.3%
class lc126 {
    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
    	List<List<String>> ans = new ArrayList<>();
        //trans the wordList to wordSet
    	Set<String> wordSet = new HashSet<>();
    	for(String word : wordList)
    		wordSet.add(word);

    	if(!wordSet.contains(endWord)) return ans;

    	//remove two unnessary word
    	wordSet.remove(beginWord);
    	wordSet.remove(endWord);

    	//steps to reach the word
    	Map<String, Integer> steps = new HashMap<>();
    	steps.put(beginWord, 1);

    	//adjacency map to reprents the graph
    	Map<String, List<String>> parents = new HashMap<>();

    	Queue<String> q = new LinkedList<>();
    	q.offer(beginWord);

    	int len = beginWord.length();
    	int step = 0;
    	Boolean found = false;

    	while(!q.isEmpty() && !found){
    		step ++;
    		for(int size = q.size(); size > 0; size --){
    			String orgWord = q.remove();
    			char [] wordArray = orgWord.toCharArray();

    			for(int i = 0; i < len; i++){
    				char c = wordArray[i];
    				for(char ch = 'a'; ch <= 'z'; ch ++){
    					//little optimization reduce run time to 145ms beats 56.9%
    					if(ch == c) continue;
    					
    					wordArray[i] = ch;
    					String newWord = String.valueOf(wordArray);

    					if(!endWord.equals(newWord)){
    						if(parents.get(endWord) == null)
    							parents.put(endWord, new ArrayList<>());
    						parents.get(endWord).add(orgWord);
    						found = true;
    					}else{
    						Integer stp = steps.get(newWord);
    						//not a new word, but another transform with the same steps
    						if(stp != null && step + 1 == stp)
    							parents.get(newWord).add(orgWord);
    					}

    					if(!wordSet.contains(newWord)) continue;
    					wordSet.remove(newWord);
    					q.offer(newWord);
    					steps.put(newWord, step + 1);
    					List<String> parents_ = new ArrayList<>();
    					parents_.add(orgWord);
    					parents.put(newWord, parents_);
    				}
    				wordArray[i] = c;
    			}
    		}
    	}

    	if(found){
    		List<String> cur = new ArrayList<>();
    		cur.add(endWord);
    		getPaths(endWord, beginWord, parents, cur, ans);
    	}

    	return ans;
    }

    private void getPaths(String word, String beginWord, Map<String, List<String>> parents, 
    						List<String> cur, List<List<String>> ans){

    	if(word.equals(beginWord)){
    		List<String> res = new ArrayList<>(cur);
    		Collections.reverse(res);
    		ans.add(res);
    		return;
    	}

    	for(String p : parents.get(word)){
    		cur.add(p);
    		getPaths(p, beginWord, parents, cur, ans);
    		//restore state
    		cur.remove(cur.size() - 1);
    	}
    }
}