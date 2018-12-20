import java.util.*;
class lc72_DP {
	
	//Solution 2 : DP
	//Time: O(m * n) m, n the length of word1, word2
	//Space: O(m * n)
	//Runtime: 6ms beats 84.6%

	public int minDistance(String word1, String word2) {
        int l1 = word1.length();
        int l2 = word2.length();

        //unnessary but faster a little bit
        if(l1 == 0) return l2;
        if(l2 == 0) return l1;


        //init dp array
        //dp[i][j] -> minDistance(word1[0:i], word2[0:j])
		int [][] dp = new int[l1 + 1][l2 + 1];
        for(int i = 0; i <= l1; i++)
            dp[i][0] = i;
        for(int i = 0; i <= l2; i++)
            dp[0][i] = i;

        for(int i = 1; i <= l1; i++)
            for(int j = 1; j <= l2; j++){
                if(word1.charAt(i - 1) == word2.charAt(j - 1))
                    dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = 1 + Math.min(Math.min(dp[i - 1][j], dp[i][j - 1]),
                                        dp[i - 1][j - 1]);
            }

        return dp[l1][l2];
    }
   
}