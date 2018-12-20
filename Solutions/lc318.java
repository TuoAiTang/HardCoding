import java.util.*;
class lc318 {
	//SOlution 1: sort + HashTable
	//Time: O(nlogn + len * n^2) len -> the length of the longest word
	//Space: O(26 * n ^ 2)
    public int maxProduct1(String[] words) {
        //Arrays.sort(words, (a, b) -> b.length() - a.length());	//288ms lambda

        //201ms anonymous class
        Arrays.sort(words, new Comparator<String>(){
        	@Override
        	public int compare(String a, String b){
        		return b.length() - a.length();
        	}
        });
        int ans = 0;
        for(int i = 0; i < words.length; i++)
        	for(int j = i + 1; j < words.length; j++)
        		if(!hasCommon(words[i], words[j])){
        			ans = Math.max(ans, words[i].length() * words[j].length());
        			break;
        		}

        return ans;
    }

    //Time: O(2 * len)
    //Space: O(len)
    private boolean hasCommon(String a, String b){
    	if(a.length() == 0 || b.length() == 0) return false;
    	char [] map = new char[26];
    	for(char c : a.toCharArray())
    		++map[c - 'a'];
    	for(char c : b.toCharArray())
    		if(map[c - 'a'] != 0)
    			return true;
		return false;
    }


    //Soulution 2 : pre-process sort + hashmap
    //60ms beats 29.36%
    //Time: O(nlogn + len * n^2)
    //Space: O(26 * n)
    public int maxProduct2(String[] words) {
    	if(words == null || words.length == 0) return 0;
        int ans = 0;

        //pre-process 1 : sorting
        Arrays.sort(words, new Comparator<String>(){
        	@Override
        	public int compare(String a, String b){
        		return b.length() - a.length();
        	}
        });
        
        //pre-process 2 : mapping
        int [][] premap = new int[words.length][26];
        for(int i = 0; i < words.length; i++)
        	for(char c : words[i].toCharArray())
        		premap[i][c - 'a'] = 1;

        for(int i = 0; i < words.length; i++)
        	for(int j = i + 1; j < words.length; j++){
        		boolean hasCommon = false;
        		for(char c : words[j].toCharArray())
        			if(premap[i][c - 'a'] == 1){
        				hasCommon = true;
        				break;
        			}
        		if(!hasCommon){
        			ans = Math.max(ans, words[i].length() * words[j].length());
        			break;
        		}
        	}

        return ans;
    }


    //Soulution 3 : pre-process sort + bit-manipulation
    //29ms beats 40.51% -> 20ms beats 50.83 without sorting
    //Time: O(nlogn + len * n + n^2)
    //Space: O(n)
    public int maxProduct3(String[] words) {
    	if(words == null || words.length == 0) return 0;
        int ans = 0;

        //pre-process 1 : sorting
        // Arrays.sort(words, new Comparator<String>(){
        // 	@Override
        // 	public int compare(String a, String b){
        // 		return b.length() - a.length();
        // 	}
        // });
        
        //pre-process 2 : bit-operations
       	int [] map = new int [words.length];
       	for(int i = 0; i < words.length; i++)
       		for(char c : words[i].toCharArray())
       			map[i] |= (1 << (c - 'a'));

	    for(int i = 0; i < words.length; i++)
	    	for(int j = i + 1; j < words.length; j++)
	    		if((map[i] & map[j]) == 0)
	    			ans = Math.max(ans, words[i].length() * words[j].length());
	    			

        return ans;
    }
}