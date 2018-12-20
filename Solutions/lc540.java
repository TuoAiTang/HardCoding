/*	
	Test Case 1: [1,1,2,3,3,4,4,8,8]

	l = 0, r = 9
	mid = 4
	n = 5
	nums[mid] != nums[n]
	r = mid = 4


	mid = 2
	n = 3
	nums[mid] != nums[n]
	r = 2

	mid = 1
	n = 0
	nums[mid] == nums[n]
	l = 2

*/
class lc540 {
	//binary search
	//Time: O(logn)
	//0ms
    public int singleNonDuplicate(int[] nums) {
        int l = 0;
        int r = nums.length - 1;
        while(l < r){
        	int m = (l + r) / 2;
        	// int n = (m % 2 == 0) ? (m + 1) : (m - 1);
        	int n = m ^ 1;
        	if(nums[m] == nums[n])
        		l = m + 1;
        	else
        		r = m;
        }

        return nums[r];	//nums[l] ->the same, since l == r
    }
}