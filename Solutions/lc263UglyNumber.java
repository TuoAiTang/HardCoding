//1ms beats 100%
class lc263UglyNumber {
    public boolean isUgly(int num) {
    	if(num == 0) return false;
        int [] factors = {2, 3, 5};
        for(int factor : factors)
        	while(num % factor == 0) 
        		num /= factor;
        return num == 1;
    }
}