import java.util.*;
class lc72 {
	
	//Solution 1 : memorization recursion
	//Time: O(m * n) m, n the length of word1, word2
	//Space: O(m * n)
	//Runtime: 7ms beats 74.36%
	
	private int [][] dp;

	public int minDistance(String word1, String word2) {
		int l1 = word1.length();
		int l2 = word2.length();
		dp = new int[l1 + 1][l2 + 1];
		for(int [] d : dp)
			Arrays.fill(d, -1);
		return minDistance(word1, l1, word2, l2);
        
    }

    private int minDistance(String word1, int l1, String word2, int l2){
    	if(l1 == 0) return l2;
        if(l2 == 0) return l1;
        if(dp[l1][l2] != -1) return dp[l1][l2];
        int ans = 0;
        if(word1.charAt(l1 - 1) == word2.charAt(l2 - 1))
        	ans = minDistance(word1, l1 - 1, word2, l2 - 1);

        else ans = Math.min(Math.min(minDistance(word1, l1 - 1, word2, l2),
        						 minDistance(word1, l1, word2, l2 - 1)),
        				minDistance(word1, l1 - 1, word2, l2 - 1)) + 1;
        dp[l1][l2] = ans;
    	return ans;
    }
}

/*	if word1[len1 - 1] == word2[len2 - 1]
	**	ans = minDistance(word1[0 : len1 - 2], word2[0 : len2 - 2]);
	**
	**
	**	word1 = "horse"		"11111111111111"
	**	word2 = "ros"		"22222222222222"
	**
	**	ans = 1 + min(minDisdance("hors", "ros") 2,
	**			  minDistance("horse", "ro") 4,
	**			  minDistance("hors", "ro"));
	**
	**	minDistance("", "") = 0;
	**	minDistance(s, "") = s.length;
	**	minDistance("", s) = s.length;
	**	
		T(n) = 3 * T(n - 1) + O(1)
    **
	*/