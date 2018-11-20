import java.util.*;
//212ms beats 32.46%
class lc126_bfs2{
	public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList){
		List<List<String>> ans = new ArrayList<>();
        //trans the wordList to wordSet
    	Set<String> wordSet = new HashSet<>();
    	for(String word : wordList)
    		wordSet.add(word);

    	if(!wordSet.contains(endWord)) return ans;

    	//remove these two unnessary word
    	wordSet.remove(beginWord);
    	wordSet.remove(endWord);

    	Set<String> q = new HashSet<>();
    	q.add(beginWord);
    	
    	Map<String, List<String>> children = new HashMap<>();
    	Boolean found = false;
    	int len = beginWord.length();

    	while(!q.isEmpty() && !found){
    		deleteWordThisLevel(q, wordSet);
    		Iterator<String> it = q.iterator();
    		Set<String> tmp = new HashSet<>();
    		while(it.hasNext()){
    			String orgWord = it.next();
    			char [] wordArray = orgWord.toCharArray();
    			for(int i = 0; i < len; i++){
    				char c = wordArray[i];
    				for(char ch = 'a'; ch <= 'z'; ch++){
    					wordArray[i] = ch;
    					String newWord = String.valueOf(wordArray);
    					if(endWord.equals(newWord)){
    						if(children.get(orgWord) == null)
    							children.put(orgWord, new ArrayList<>());
    						children.get(orgWord).add(endWord);
    						found = true;
    					}else if(wordSet.contains(newWord) && !found){
    						tmp.add(newWord);
    						if(children.get(orgWord) == null)
    							children.put(orgWord, new ArrayList<>());
    						children.get(orgWord).add(newWord);
    					}
    				}
    				wordArray[i] = c;
    			}
    		}
    		q = tmp;
    	}
    	System.out.println(children);
    	if(found){
    		List<String> cur = new ArrayList<>();
    		cur.add(beginWord);
    		getPaths(beginWord, endWord, children, cur, ans);
    	}

    	return ans;
	}

	private void getPaths(String word, String endWord, Map<String, List<String>> children,
							List<String> cur, List<List<String>> ans){

		if(word.equals(endWord)){
			ans.add(new ArrayList<>(cur));
			return;
		}

		if(!children.containsKey(word))
			return;

		for(String child : children.get(word)){
			cur.add(child);
			getPaths(child, endWord, children, cur, ans);
			cur.remove(cur.size() - 1);
		}

	}

	private void deleteWordThisLevel(Set<String> s1, Set<String> s){
		Iterator<String> it = s1.iterator();
		while(it.hasNext())
			s.remove(it.next());
	}
}
