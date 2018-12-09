//566ms beats 5.94%
//Time: O(n^2 * 2^n)
//Space: O(n * 2^n)
import java.util.*;
class lc943_DP {

    public String shortestSuperstring(String[] A) {
        int n = A.length;

        //pre-process to caculate the cost of (j append to i)
        int [][] cost = new int[n][n];
        for(int i = 0; i < n; i++){
        	for(int j = 0; j < n; j++){
        		int li = A[i].length();
        		int lj = A[j].length();
        		cost[i][j] = lj;
        		for(int k = 1; k <= Math.min(li, lj); k++){
        			//k character in the tail of i, while the head of j
        			if(A[i].substring(li - k).equals(A[j].substring(0, k)))
        				cost[i][j] = lj - k;
        		}
        	}
        }

        int [][] dp = new int [1 << n][n];  //dp[s][i] -> all nodes in s, to i, the lowest cost
        for(int [] a : dp)
            Arrays.fill(a, Integer.MAX_VALUE / 2);  //avoid overflow

        for(int i = 0; i < n; i++)
            dp[1 << i][i] = A[i].length(); 

        int [][] parents = new int [1 << n][n];
        for(int [] a : parents)
            Arrays.fill(a, -1);

        for(int s = 1; s < (1 << n); s++){
            for(int i = 0; i < n; i++){
                if((s & (1 << i)) == 0) continue;
                int ps = s & ~(1 << i);
                for(int j = 0; j < n; j++){
                    if(dp[ps][j] + cost[j][i] < dp[s][i]){
                        dp[s][i] = dp[ps][j] + cost[j][i];
                        parents[s][i] = j;
                    }
                }
            }
        }

        int s = (1 << n) - 1;
        int j = getMinIdx(dp[s]);
        String ans = "";
        while(s > 0){
            int i = parents[s][j];
            if(i < 0) return A[j] + ans;
            ans = A[j].substring(A[j].length() - cost[i][j]) + ans;
            s &= ~(1 << j);
            j = i;
        }
        return ans;
   }

   private int getMinIdx(int [] a) {
        int idx = 0;
        for(int i = 1; i < a.length; i++)
            if(a[idx] > a[i])
                idx = i;
        return idx;
   }
}