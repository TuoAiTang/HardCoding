import java.util.*;
class lc732{

}
//Solution 1: scanning
//Time:O(n * n * logn)
//Space: O(n)
//Runntime: 221ms beats 38.12%
class MyCalendarThree {
	private TreeMap<Integer, Integer> delta;
	private int k_;
    public MyCalendarThree() {
        delta = new TreeMap<>();
        k_ = 0;
    }
    
    public int book(int start, int end) {
        delta.put(start, delta.getOrDefault(start, 0) + 1);
        delta.put(end, delta.getOrDefault(end, 0) - 1);
        int count = 0;
        //O(nlogn)
        for(Map.Entry et : delta.entrySet()){
        	count += (int) et.getValue();
        	k_ = Math.max(k_, count);
        	if((int) et.getKey() >= end) break;	//pruning 
        }
        return k_;
    }
}