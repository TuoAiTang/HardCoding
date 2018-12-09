/*	Version: HashMap + LinkedList
**	Time: O(1)
**	Runtime: 146ms beats 25.35%
**
**	
**	Map freq_map -> (freq, the head of nodes which has same freq)
**	Map key_map -> (key, the exact node)
**  Bucket<cache node> the latest in the head, no need to count tick
*/
import java.util.*;
class lc460_2{
    LFUCache lfu;
}
class LFUCache {

    private Map<Integer, BucketList> freq_map = new HashMap<>(); 
    private Map<Integer, Bucket> key_map = new HashMap<>();
    private int capacity;
    private int min_freq;

    public LFUCache(int capacity) {
        freq_map = new HashMap<>();
        key_map = new HashMap<>();
        min_freq = 0;
        this.capacity = capacity;
    }
    
    public int get(int key) {
        Bucket bk = key_map.get(key);
        if(bk == null) return -1;
        touch(bk);
        return bk.cn.val;
    }
    
    public void put(int key, int value) {
        if(capacity == 0) return;
        Bucket bk = key_map.get(key);
        //already exsists
        if(bk != null){
            touch(bk);
            bk.cn.val = value;
        }
        //dosen't exists
        else{
            if(key_map.size() == capacity){
                BucketList bl = freq_map.get(min_freq);
                key_map.remove(bl.removeLast().cn.key);
                if(bl.isEmpty())
                    freq_map.remove(min_freq);
            }
            min_freq = 1;
            CacheNode cn = new CacheNode(key, value, 1);
            Bucket nbk = new Bucket(cn);
            if(freq_map.get(min_freq) == null)
                freq_map.put(1, new BucketList());
            freq_map.get(1).addFirst(nbk);
            key_map.put(key, nbk);  
        }
    }

    private void touch(Bucket bk){
        CacheNode cn = bk.cn;
        int prev_freq = cn.freq;
        int new_freq = ++(cn.freq);

        BucketList bl = freq_map.get(prev_freq);
        bl.remove(bk);

        if(bl.isEmpty()){
            freq_map.remove(prev_freq);
            if(prev_freq == min_freq)
                min_freq = new_freq;
        }

        if(freq_map.get(new_freq) == null)
            freq_map.put(new_freq, new BucketList());

        Bucket nbk = new Bucket(cn);

        freq_map.get(new_freq).addFirst(nbk);
        key_map.put(cn.key, nbk);
    }

    class Bucket{
        CacheNode cn;
        Bucket prev, next;
        Bucket(CacheNode cn){
            this.cn = cn;
        }
    }

    class BucketList{
        Bucket head, tail;
        BucketList(){
            head = new Bucket(null);
            tail = new Bucket(null);
            head.next = tail;
            tail.prev = head;
        }
        boolean isEmpty(){
            return tail.prev == head;
        }
        void addFirst(Bucket bk){
            bk.next = head.next;
            head.next.prev = bk;
            bk.prev = head;
            head.next = bk;
        }
        void remove(Bucket bk){
            bk.next.prev = bk.prev;
            bk.prev.next = bk.next;
        }
        Bucket removeLast(){
            if(isEmpty()) return null;
            Bucket ret = tail.prev;
            tail.prev = tail.prev.prev;
            tail.prev.next = tail;
            return ret;
        }
    }

    class CacheNode{
        int key;
        int val;
        int freq;

        public CacheNode(int key, int val, int freq){
            this.key = key;
            this.val = val;
            this.freq = freq;
        }
    }
}