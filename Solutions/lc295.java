package heap;
import java.util.*;
public class lc295 {
	public static void main(String[] args) {
		MedianFinder mf = new MedianFinder();
		mf.addNum(1);
		mf.addNum(2);
		mf.addNum(-1);
		System.out.println(mf.findMedian());
		
		String a = "ab";
		String b = "bac";
		System.out.println(a.compareTo(b));
	}
}

class MedianFinder {
	//a is less than b
	PriorityQueue<Integer> leftMaxHeap = new PriorityQueue<>(
    		new Comparator<Integer>() {
    			@Override
    			public int compare(Integer a, Integer b) {
    				return a - b < 0 ? 1 : -1;
    			}
    			
    		});
	//a is greater than b
    PriorityQueue<Integer> rightMinHeap = new PriorityQueue<>(
    		new Comparator<Integer>() {
    			@Override
    			public int compare(Integer a, Integer b) {
    				return a - b > 0 ? 1 : -1;
    			}    			
    		});
    /** initialize your data structure here. */
    public MedianFinder() {
   
    }
    
    public void addNum(int num) {
        if(leftMaxHeap.isEmpty() || num <= leftMaxHeap.peek())
        	leftMaxHeap.offer(num);
        else
        	rightMinHeap.offer(num);
        //balance the left and right
        if(leftMaxHeap.size() < rightMinHeap.size())
        	leftMaxHeap.offer(rightMinHeap.poll());
    	else if(leftMaxHeap.size() - rightMinHeap.size() == 2)
        	rightMinHeap.offer(leftMaxHeap.poll());
        
    }
    
    public double findMedian() {
        if(leftMaxHeap.size() == rightMinHeap.size())
        	return (double)(leftMaxHeap.peek() + rightMinHeap.peek()) / 2;
        else
        	return (double)(leftMaxHeap.peek());
    }
}


