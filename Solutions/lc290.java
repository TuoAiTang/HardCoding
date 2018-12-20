import java.util.*;
class lc290 {
	//2ms beats 41.5%
	//two map
	//Time: O(n) -> one pass
	//Space: O(n)
    public boolean wordPattern(String pattern, String str) {
        Map<Character, String> map1 = new HashMap<>();
        Map<String, Character> map2 = new HashMap<>();

        String [] words = str.split(" ");
        int n = words.length;
        if(n != pattern.length()) return false;

        for(int i = 0; i < n; i++){

        	char c = pattern.charAt(i);
        	String s = words[i];

        	if(map1.containsKey(c)){
        		if(!map1.get(c).equals(s))
        			return false;
        	}
        	else map1.put(c, s);

        	if(map2.containsKey(s)){
        		if(map2.get(s) != c)
        			return false;
        	}
        	else map2.put(s, c);
        }

        return true; 
    }

    //1ms beats 99.34%
    //one map + one set
	//Time: O(n) -> one pass
	//Space: O(n)
    public boolean wordPattern2(String pattern, String str) {
        Map<Character, String> map = new HashMap<>();
        Set<String> set = new HashSet<>();

        String [] words = str.split(" ");
        int n = words.length;
        if(n != pattern.length()) return false;

        for(int i = 0; i < n; i++){

        	char c = pattern.charAt(i);
        	String s = words[i];

        	if(map.containsKey(c)){
        		if(!map.get(c).equals(s))
        			return false;
        	}
        	else {
        		if(set.contains(s)) return false;
        		set.add(s);
        		map.put(c, s);
        	}
        }

        return true; 
    }
}