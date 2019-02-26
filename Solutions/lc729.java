import java.util.*;
class lc729{

}
//101ms beats 75.18%
//Solution : binary search tree
//Time: O(nlogn) continious n booking cost
//Space: O(n)
class MyCalendar {

	TreeMap<Integer, Integer> tm;

    public MyCalendar() {
        tm = new TreeMap<>();
    }
    
    public boolean book(int start, int end) {
    	//the greatest key less than or equal to start
        Integer fk = tm.floorKey(start);
        //the least key greater than or equal to start
        Integer ck = tm.ceilingKey(start);
        if(fk != null && tm.get(fk) > start) return false;
        if(ck != null && ck < end) return false;

        tm.put(start, end);
        return true;
    }
}