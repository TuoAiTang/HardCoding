package heap;
import java.util.*;
public class lc692 {
	public List<String> topKFrequent(String[] words, int k) {
        LinkedList<String> res = new LinkedList<>();
        Map<String, Integer> hm = new HashMap<>();
        for(String word : words){
            hm.put(word, hm.getOrDefault(word, 0) + 1);
        }
        PriorityQueue<String> minheap = new PriorityQueue<>(
        		new Comparator<String>() {

					@Override
					public int compare(String o1, String o2) {
						if(hm.get(o1) == hm.get(o2))
							return o2.compareTo(o1);
						return hm.get(o1) - hm.get(o2);
					}
        			
				});
        for(String word : hm.keySet()) {
        	minheap.offer(word);
        	if(minheap.size() > k)
        		minheap.remove();      		
        }
        while(!minheap.isEmpty())
        	res.addFirst(minheap.poll());
        return res;      
    }
	
}
