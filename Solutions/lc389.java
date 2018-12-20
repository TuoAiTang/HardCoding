import java.util.*;
class lc389 {
	//3ms beats 99.3%
	//Hashtable
    public char findTheDifference1(String s, String t) {
        int [] smap = new int[26];
        int [] tmap = new int[26];
        for(int i = 0; i < s.length(); i++){
        	++smap[s.charAt(i) - 'a'];
        	++tmap[t.charAt(i) - 'a'];
        }

        ++tmap[t.charAt(t.length() - 1) - 'a'];

        for(char c = 'a'; c <= 'z'; c++)
        	if(smap[c - 'a'] < tmap[c - 'a'])
        		return c;

        return 'a';		//un-reached
    }

    //6ms beats 48.79 %
	//XOR
    public char findTheDifference2(String s, String t) {
        int x = 0;
        for(char c : s.toCharArray())
        	x ^= c - 'a';
        for(char c : t.toCharArray())
        	x ^= c - 'a';
        return (char)('a' + x);		
    }
}