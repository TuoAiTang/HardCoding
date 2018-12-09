/*	Version: HashMap + balanced BST
**	Time: O(log(cap))
**	Runtime: 156ms beats 20.24%
**
**	Use TreeMap(balenced binary tree) cache to store the cache node
**	to achieve log(cap) operation.
**	And a hashmap map the (key, cache node) 
*/
import java.util.*;
class LFUCache {

	private TreeSet<CacheNode> cache;
	private HashMap<Integer, CacheNode> map;
	private int tick_;
	private int cap;

    public LFUCache(int capacity) {
        cache = new TreeSet<>();
        map = new HashMap<>();
        tick_ = 0;
        cap = capacity;
    }
    
    public int get(int key) {
        CacheNode cn = map.get(key);
        if(cn == null) return -1;
        touch(cn);
        return cn.val;
    }
    
    public void put(int key, int value) {
        if(cap == 0) return;
        CacheNode cn = map.get(key);
        //already exsists
        if(cn != null){
        	touch(cn);
        	cn.val = value;
        }
        //dosen't exists
        else{
        	if(cache.size() == cap)
        		map.remove(cache.pollFirst().key);
        	cn = new CacheNode(key, value, 1, ++tick_);
        	map.put(key, cn);	
        	cache.add(cn);
        }
    }

    private void touch(CacheNode cn){
    	cache.remove(cn);
    	cn.freq++;
    	cn.tick = ++tick_;
    	cache.add(cn);
    }

    class CacheNode implements Comparable<CacheNode>{
		int key;
		int val;
		int freq;
		int tick;

		public CacheNode(int key, int val, int freq, int tick){
			this.key = key;
			this.val = val;
			this.freq = freq;
			this.tick = tick;
		}

		@Override
		public int compareTo(CacheNode b){
			if(this.freq == b.freq)
				return this.tick - b.tick;
			else
				return this.freq - b.freq;
		}
	}
}