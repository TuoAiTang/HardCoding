import java.util.*;
class lc819 {
	//9ms beats 85.13%
	//Time: O(n) n -> the length of paragraph
	//Space: O(m + n) m, the banned word size; n, the unique words in paragraph;
    public String mostCommonWord(String paragraph, String[] banned) {
        Set<String> banWords = new HashSet<>();
        for(String bw : banned)
        	banWords.add(bw);

        int i = 0;
        int n = paragraph.length();
        int maxFreq = 0;
        String ans = null;
        Map<String, Integer> map = new HashMap<>();
        while(i < n){
        	if(!isLetter(paragraph.charAt(i))) {
                i++;
                continue;
            }
        	int j = i + 1;
        	while(j < n && isLetter(paragraph.charAt(j))) j++;
        	String word = paragraph.substring(i, j).toLowerCase();
        	if(!banWords.contains(word)){
        		int freq = map.getOrDefault(word, 0) + 1;
        		map.put(word, freq);
        		if(freq > maxFreq){
        			maxFreq = freq;
        			ans = word;
        		}
        	}
        	i = j;
        }

        return ans;
    }

    private boolean isLetter(char c){
    	int lc = c - 'a';
    	int tc = c - 'A';
    	if(lc >= 0 && lc < 26)
    		return true;
    	if(tc >= 0 && tc < 26)
    		return true;
    	return false;
    }
}