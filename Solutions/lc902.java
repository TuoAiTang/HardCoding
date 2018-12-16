class lc902 {
	//5ms beats 46.54%
	//Time: (D.length * logN)
    public int atMostNGivenDigitSet(String[] D, int N) {
        int ans = 0;
        //transform to easier get every digit
        char [] s = String.valueOf(N).toCharArray();
        int n = s.length;

        for(int i = 1; i < n; i++)
        	ans += Math.pow(D.length, i);

        for(int i = 0; i < n; i++){
        	boolean prefix_in_set = false;
        	for(String d : D){
        		if(d.charAt(0) < s[i])
        			ans += Math.pow(D.length, n - i - 1);
        		else if(d.charAt(0) == s[i]){
        			prefix_in_set = true;
        			break;
        		}
        	}
        	if(!prefix_in_set) return ans;
        }

        return ans + 1;
    }
}