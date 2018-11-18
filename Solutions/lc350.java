import java.util.*;
class lc350 {
	//Time: O(m + n + mlogm + nlogn)
	//Space: O(m)
    public int[] intersect(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        int [] res = new int[nums1.length];
        int i = 0, j = 0, idx = 0;
        while(i < nums1.length && j < nums2.length){
        	if(nums1[i] > nums2[j]) j++;

        	else if(nums1[i] < nums2[j]) i++;

        	else{
        		res[idx++] = nums1[i];
        		i++;
        		j++;
        	}
        }
        return Arrays.copyOfRange(res, 0, idx);
    }

    // public int[] intersect(int[] nums1, int[] nums2) {
    //     Map<Integer, Integer> map1 = new HashMap<>();
    //     Map<Integer, Integer> map2 = new HashMap<>();
    //     List<Integer> res = new ArrayList<>();
        
    //     for(int num : nums1)
    // 		map1.put(num, map1.getOrDefault(num, 0) + 1);
    //     for(int num : nums2)
    //     	map2.put(num, map2.getOrDefault(num, 0) + 1);

    //     for(int key : map2.keySet()){
    //     	int count = Math.min(map1.getOrDefault(key, 0), map2.get(key));
    //     	for(int i = 0; i < count; i++)
    //     		res.add(key);
    //     }


    //     int ans[] = new int[res.size()];
    //     int idx = 0;
    //     for(Integer num : res)
    //     	ans[idx++] = num;
    //     return ans;
    // }


}