//filter method
//15ms beats 74.79%
import java.util.*;
class lc204 {
    public int countPrimes(int n) {
    	//p[i] == 0 -> not prime
    	//p[i] == 1 -> prime
        boolean [] p = new boolean [n];
       	for(int i = 2; i < n; i++)
       		p[i] = true;
        for(int i = 2; i * i < n; i++)
        	if(p[i]){
        		for(long j = i * i; j < n; j += i)
        			p[(int)j] = false;
        	}

        int ans = 0;
        for(boolean x : p)
        	ans += x ? 1 : 0;
        return ans;
    }
}