import java.util.*;
class lc91_DP {
    //Time: O(n)
    //Space: O(1)
    //1ms beats 95.08%
    public int numDecodings(String s) {
    	if(s == null || s.startsWith("0")) return 0;
        int n = s.length();
        if(n == 1) return 1;
        int w1 = 1; //dp[i - 1]
        int w2 = 1; //dp[i - 2]
        int w;

        for(int i = 1; i < n; i++){
            w = 0;
            if(isValid(s.charAt(i))) w += w1;
            if(isValid(s.charAt(i - 1), s.charAt(i))) w += w2;
            if(w == 0) return 0;    //both invalid
            w2 = w1;
            w1 = w;
        }
        return w1;
    }

    private boolean isValid(char c){ return c != '0'; }
    private boolean isValid(char c1, char c2){
        int n = (c1 - '0') * 10 + (c2 - '0');
        return n >= 10 && n <= 26;
    }    
}