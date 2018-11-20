import java.util.*;
//27ms beats 96.89%
class lc126_Bidirection_BFS{
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

    	Set<String> s1 = new HashSet<>();
    	Set<String> s2 = new HashSet<>();
    	s1.add(beginWord);
    	s2.add(endWord);

    	Map<String, List<String>> children = new HashMap<>();

    	int len = beginWord.length();
    	Boolean found = false;
    	Boolean backward = false;

    	while(!s1.isEmpty() && !s2.isEmpty() && !found){
    		//swap s1, s2 --> always expand the smaller word set
    		if(s1.size() > s2.size()){
	    		Set<String> tmp_set = s1;
	    		s1 = s2;
	    		s2 = tmp_set;
	    		backward = !backward;
    		}
    		deleteWordThisLevel(s1, wordSet);
    		Iterator<String> it = s1.iterator();
    		Set<String> s = new HashSet<>();
    		while(it.hasNext()){
    			String orgWord = it.next();
    			char [] wordArray = orgWord.toCharArray();
    			//O(26 * l), expand to (26 * l - 1) words
    			for(int i = 0; i < len; i++){
    				char c = wordArray[i];
    				for(char ch = 'a'; ch <= 'z'; ch++){
    					if(ch == c) continue;
    					wordArray[i] = ch;
    					String newWord = String.valueOf(wordArray);
    					String pw = backward ? newWord : orgWord;
    					String cw = backward ? orgWord : newWord;
    					if(s2.contains(newWord)){
    						if(!children.containsKey(pw))
    							children.put(pw, new ArrayList<>());
    						children.get(pw).add(cw);
    						found = true;
    					}else if(wordSet.contains(newWord) && !found){
    						s.add(newWord);
    						if(!children.containsKey(pw))
    							children.put(pw, new ArrayList<>());
    						children.get(pw).add(cw);
    					}
    				}
    				wordArray[i] = c;
    			}
    		}
    		s1 = s;
    	}

    	if(found){
    		List<String> path = new ArrayList<>();
    		path.add(beginWord);
    		getPaths(beginWord, endWord, children, path, ans);
    	}

    	return ans;
	}

	private void deleteWordThisLevel(Set<String> s1, Set<String> s){
		Iterator<String> it = s1.iterator();
		while(it.hasNext())
			s.remove(it.next());
	}

	private void getPaths(String word, String endWord, Map<String, List<String>> children,
							List<String> path, List<List<String>> ans){

		if(word.equals(endWord)){
			ans.add(new ArrayList<>(path));
			return;
		}

		if(!children.containsKey(word))
			return;

		for(String child : children.get(word)){
			path.add(child);
			getPaths(child, endWord, children, path, ans);
			path.remove(path.size() - 1);
		}

	}
}