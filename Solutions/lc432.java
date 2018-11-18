package hashtable;

import java.util.*;


public class lc432 {
	public static void main(String[] args) {
		AllOne ao = new AllOne();
		String[] str_list = {"a","b","c","d","a", "b", "c", "d", "c", "d", "c", "d", "d", "a"};
		for (String string : str_list) {
			ao.inc(string);
		}
		System.out.println("max : " + ao.getMaxKey());
		System.out.println("min : " + ao.getMinKey());
	}
}

class AllOne {
	
	private Map<String, Bucket> map;
	private Bucket head;
	private Bucket tail;	
	
	private class Bucket{
		int freq;
		Set<String> set;
		Bucket prev;
		Bucket next;
		
		public Bucket(int freq) {
			this.freq = freq;
			this.set = new HashSet<>();
		}
	}

    /** Initialize your data structure here. */
    public AllOne() {
        map = new HashMap<>();
        head = new Bucket(Integer.MIN_VALUE);
        tail = new Bucket(Integer.MAX_VALUE);
        head.next = tail;
        tail.prev = head;
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    public void inc(String key) {
    	if(map.containsKey(key))
    		changeBucketForward(key);
    	else {
    		if(head.next.freq != 1)
    			//add an empty bucket, then add key into it
    			addBucketAfter(new Bucket(1), head);
    		head.next.set.add(key);
    		map.put(key, head.next);
    	}
//    	System.out.println("after inc| freq : " + map.get(key).freq + " key : " + key);
    }  

	/** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    public void dec(String key) {
    	if(map.containsKey(key)) {
    		int freq = map.get(key).freq;
    		if(freq == 1) {
    			removeFromBucket(map.get(key), key);
    			map.remove(key);
    		}else {
    			changeBucketBackward(key);
    		}
    	}   	
	}
	
	/** Returns one of the keys with maximal value. */
    public String getMaxKey() {
       return tail.prev == head ? "" : tail.prev.set.iterator().next();
    }
    
    /** Returns one of the keys with Minimal value. */
    public String getMinKey() {
        return head.next == tail ? "" : head.next.set.iterator().next();
    }
    
    private void changeBucketForward(String key) {
		Bucket oldBk = map.get(key);
		Bucket newBk;
		int freq = oldBk.freq;
//		System.out.println("changeBucketForward freq : " + freq + " key : " + key);
		if(oldBk.next.freq != freq + 1) {
			newBk = new Bucket(freq + 1);
			addBucketAfter(newBk, oldBk);			
		}
		else
			newBk = oldBk.next;
			
		newBk.set.add(key);
		removeFromBucket(oldBk, key);
		map.put(key, newBk);
	}
    
    private void changeBucketBackward(String key) {
		Bucket oldBk = map.get(key);
		Bucket newBk;
		int freq = oldBk.freq;
		if(oldBk.prev.freq != freq - 1) {
			newBk = new Bucket(freq - 1);
			addBucketAfter(newBk, oldBk.prev);
		}
		else
			newBk = oldBk.prev;
		
		newBk.set.add(key);
		removeFromBucket(oldBk, key);
		map.put(key, newBk);
	}
    
    private void addBucketAfter(Bucket newBucket, Bucket preBucket) {
		newBucket.next = preBucket.next;
		newBucket.prev = preBucket;
		preBucket.next.prev = newBucket;
		preBucket.next = newBucket;
	}	
    
    private void removeFromBucket(Bucket bucket, String key) {
		bucket.set.remove(key);
		if(bucket.set.size() == 0) {
			//remove empty bucket from the list
			bucket.prev.next = bucket.next;
			bucket.next.prev = bucket.prev;
		}		
	}
    
}

