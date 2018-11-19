import java.util.*;

//33ms beats 91.58%
class lc127_Bidirectional_BFS{

	public int ladderLength(String beginWord, String endWord, List<String> wordList){
		//trans the wordList to wordSet
    	Set<String> wordSet = new HashSet<>();
    	for(String word : wordList)
    		wordSet.add(word);

    	if(!wordSet.contains(endWord)) return 0;

        int len = beginWord.length();
        int steps = 0;

        Set<String> left = new HashSet<>();
        Set<String> right = new HashSet<>();

        left.add(beginWord);
        right.add(endWord);

        while(!left.isEmpty() && !right.isEmpty()){
        	++steps;

        	Set<String> s = new HashSet<>();
        	Boolean flag = left.size() < right.size() ? true : false;
        	Iterator<String> it = flag ? left.iterator() : right.iterator();

        	while(it.hasNext()){
        		String word = it.next();
        		char [] wordArray = word.toCharArray();
        		for(int i = 0; i < len; i++){
        			char c = wordArray[i];
        			for(char j = 'a';  j <= 'z'; j++){

        				wordArray[i] = j;

        				String newWord = String.valueOf(wordArray);

        				if(flag && right.contains(newWord)) return steps + 1;

        				if(!flag && left.contains(newWord)) return steps + 1;

        				if(!wordSet.contains(newWord)) continue;

        				wordSet.remove(newWord);

        				s.add(newWord);
        			}
        			wordArray[i] = c;
        		}
        	}

        	if(flag)
        		left = s;
        	else
        		right = s;
        }

        return 0;
	}

}