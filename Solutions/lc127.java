import java.util.*;

//140ms beats 41.60%
class lc127 {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
    	//trans the wordList to wordSet
    	Set<String> wordSet = new HashSet<>();
    	for(String word : wordList)
    		wordSet.add(word);

    	if(!wordSet.contains(endWord)) return 0;


        int len = beginWord.length();
        int steps = 0;

        Queue<String> q = new LinkedList<>();
        q.offer(beginWord);

        while(!q.isEmpty()){
        	steps++;
        	for(int size = q.size(); size > 0; size--){
        		String word = q.remove();
        		char [] wordCA = word.toCharArray();
        		for(int i = 0; i < len; i ++){
        			char c = word.charAt(i);
        			for(char j = 'a'; j <= 'z'; j++){
        				//change the word at position i
        				wordCA[i] = j;
        				String newWord = String.valueOf(wordCA);
        				//result found, return
        				if(endWord.equals(newWord)) return steps + 1;
        				//skip the word which wordSet doesn't contain
        				if(!wordSet.contains(newWord)) continue;
        				//remove the word to avoid dead loop, each word in the set can only be used once
        				wordSet.remove(newWord);
        				q.offer(newWord);
        			}
        			//restore the character in position i, for only one character at one change
        			wordCA[i] = c;
        		}
        	}
        }

        return 0;
    }
}