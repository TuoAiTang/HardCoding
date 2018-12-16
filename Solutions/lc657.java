import java.util.*;
class lc657 {
	// 16ms beats 27.64 %
    public boolean judgeCircle(String moves) {
        int [] map = new int[26];
        for(int i = 0; i < moves.length(); i++)
        	++map[moves.charAt(i) - 'A'];
        return map['R' - 'A'] == map['L' - 'A'] && map['U' - 'A'] == map['D' - 'A'];
    }
}