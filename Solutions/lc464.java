//MR - minmax
//17MS beats 95.56%
//Time: O(2^n) <-- without memory O(n!) LTE
//Space: O(2^n)
class lc464 {
	private byte [] memo;
    public boolean canIWin(int maxChoosableInteger, int desiredTotal) {
    	if(desiredTotal <= 0) return true;
    	if((maxChoosableInteger + 1) * maxChoosableInteger / 2 < desiredTotal)
    		return false;
        memo = new byte[1 << maxChoosableInteger];
        return canIWin(maxChoosableInteger, desiredTotal, 0);
    }

    private boolean canIWin(int m, int t, int used){
    	if(t <= 0) return false;
    	if(memo[used] != 0) return memo[used] == 1;

    	for(int i = 0; i < m; i++){
    		if((used & (1 << i)) != 0) continue;
    		if(!canIWin(m, t - i - 1, used | (1 << i))){
    			memo[used] = 1;
    			return true;
    		}
    	}

    	memo[used] = -1;
    	return false;
    }
}