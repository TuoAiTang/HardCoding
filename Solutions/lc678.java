class lc678 {

	//MR
	//Time: O(n^3)
	//Space: O(n^2)
	//34ms beats 28.09%
    public boolean checkValidString(String s) {
    	int n = s.length();
    	char [] str = s.toCharArray();
    	//0, not solved;
        //1, true, solved;
        //-1, false, solved;
        int [][] memo = new int[n][n];
        return isValid(str, 0, n - 1, memo);
    }

    private boolean isValid(char [] str, int i, int j, int [][] memo){
    	if(i > j) return true;
    	if(memo[i][j] != 0) return memo[i][j] == 1;
    	if(i == j){
    		memo[i][i] = (str[i] == '*' ? 1 : -1);
    		return memo[i][i] == 1;
    	}

    	if((str[i] == '(' || str[i] == '*') && (str[j] == ')' || str[j] == '*')
    										&& isValid(str, i + 1, j - 1, memo)){
    		memo[i][j] = 1;
    		return true;
    	}
    	
    	for(int k = i; k < j; k++){
    		if(isValid(str, i, k, memo) && isValid(str, k + 1, j, memo)){
    			memo[i][j] = 1;
    			return true;
    		}
    	}

    	memo[i][j] = -1;
    	return false;
    }
}