import java.util.*;
class lc891 {
	
    public int sumSubseqWidths(int[] A) {
    	//25ms beats 93.75%
		//Time: O(nlogn) -> sort
        // Arrays.sort(A);
        countingSort(A);	//19ms beats 99%
        int mod = (int) 1e9 + 7;
        long ans = 0;
        long p = 1;
        for(int i = 0; i < A.length; i++){
        	ans = (ans + (A[i] - A[A.length - i - 1]) * p) % mod;
            p = (p << 1) % mod;
        }
        return (int) (ans + mod) % mod;
    }

    private void countingSort(int [] arr){
    	int max = Integer.MIN_VALUE;
    	int min = Integer.MAX_VALUE;

    	for(int a : arr){
    		min = Math.min(min, a);
    		max = Math.max(max, a);
    	}

    	int [] count = new int[max - min + 1];
    	for(int a : arr)
    		++count[a - min];

    	int i = 0;
    	int j = 0;
    	while(i < count.length){
    		if(--count[i] >= 0)
    			arr[j++] = i + min;
    		else
    			i++;
    	}
    }
}