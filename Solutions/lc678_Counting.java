class lc678_Counting {

	//counting
	//Time: O(n)
	//Space: O(1)
	//2ms beats 100&
    public boolean checkValidString(String s) {
        //min match '('
        //max match ')'
    	int min = 0;
        int max = 0;

        char [] str = s.toCharArray();
        for(int i = 0; i < str.length; i++){
            if(str[i] == '(') min++;
            else min--;
            if(str[i] != ')') max++;
            else max--;
            if(max < 0)
                return false;
            min = Math.max(0, min);
        }

        return min == 0;
    }

}