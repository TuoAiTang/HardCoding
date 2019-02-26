import java.util.*;
class lc731{
	public static void main(String[] args) {
		MyCalendarTwo mc = new MyCalendarTwo();
		mc.book(10, 20);
		mc.book(30, 40);
		System.out.println("book: (15, 25)" + mc.book(15, 25));
	}
}
//Solution 1: brute force --> most efficient
//Time:O(n^2) for n continious booking
//Space:O(2 * n)
//Runtime: 292ms beats 34.18%

class MyCalendarTwo {
	private List<Interval> booked;
	private List<Interval> overlaps;
	class Interval{
		public int start, end;
		Interval(int s, int e) {start = s; end = e;}
	}
    public MyCalendarTwo() {
        booked = new ArrayList<>();
        overlaps = new ArrayList<>();
    }
    
    public boolean book(int start, int end) {
        //check if it overlap with overlaps
        for(Interval itv : overlaps)
        	if(Math.max(itv.start, start) < Math.min(itv.end, end))
        		return false;

        //keep tracking the overlaps and add the interval to booked at last
        for(Interval itv : booked){
        	int os = Math.max(start, itv.start);
        	int oe = Math.min(end, itv.end);
        	if(os < oe) overlaps.add(new Interval(os, oe));
        }

        booked.add(new Interval(start, end));
        return true;
    }
}


//Solution 2: scanning line
//Time:O(n * n * logn) for n continious booking
//Space:O(n)
//Runtime: 538ms beats 5.09%

class MyCalendarTwo_delta {
	//orderd map
	private TreeMap<Integer, Integer> delta;
    public MyCalendarTwo() {
        delta = new TreeMap<>();
    }
    
    public boolean book(int start, int end) {
        delta.put(start, delta.getOrDefault(start, 0) + 1);
        delta.put(end, delta.getOrDefault(end, 0) - 1);
        int count = 0;
        //O(nlogn)
        for(Map.Entry et : delta.entrySet()){
        	count += (int) et.getValue();
        	if(count == 3) {
        		delta.put(start, delta.get(start) - 1);
        		delta.put(end, delta.get(end) + 1);
        		return false;
        	}
        	if((int) et.getKey() >= end) break;	//pruning reduce runtime to 405ms beats 13.16%
        }
        return true;
    }
}