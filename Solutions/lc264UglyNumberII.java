import java.util.*;
class lc264UglyNumberII {
	//206ms O(nlogn) beats 2.48%
    public static int nthUglyNumber1(int n) {
        List<Integer> uglyList = new ArrayList<>();
        int i = 0;
        for(long a = 1; a <= Integer.MAX_VALUE; a *= 2)
        	for(long b = a; b <= Integer.MAX_VALUE; b *= 3)
        		for(long c = b; c <= Integer.MAX_VALUE; c *= 5)
        			uglyList.add((int)c);

        Collections.sort(uglyList);
        return uglyList.get(n - 1);
    }

    //O(n)
    //3ms 93%
    public int nthUglyNumber2(int n) {
        int [] uglyList = new int[n];
        int i = 0;
        uglyList[i++] = 1;
        int i2 = 0, i3 = 0, i5 = 0;
        int next2, next3, next5;
        int next;
        while(i < n){
            next2 = uglyList[i2] * 2;
            next3 = uglyList[i3] * 3;
            next5 = uglyList[i5] * 5;
            next = Math.min(next2, Math.min(next3, next5));
            if(next == next2)
                i2++;
            if(next == next3)
                i3++;
            if(next == next5)
                i5++;
            uglyList[i++] = next;
        }
        return uglyList[n - 1];
    }
}