import java.util.*;
class lc728 {
    public List<Integer> selfDividingNumbers(int left, int right) {
    	List<Integer> ans = new ArrayList<>();
        for(int x = left; x <= right; x++)
        	if(isSelfDeviding(x))
        		ans.add(x);
        return ans;
    }


    //6ms beats 46.36%
    //Time: O(1)
    private boolean isSelfDeviding2(int num){
    	int x = num;
    	while(x > 0){
    		int y = num % 10;
    		if(y == 0) return false;
    		if(num % y != 0) return false;
    		x /= 10;
    	}
    	return true;
    }


    //5ms beats 60.97%
    //O(1)
    private static boolean isSelfDeviding(int num){
    	String str = String.valueOf(num);
    	for(int i = 0; i < str.length(); i++){
    		int x = str.charAt(i) - '0';
    		if(x == 0 || num % x != 0)
    			return false;
    	}
    	return true;
    }

    public static void main(String[] args) {
    	int a = 128;
    	System.out.println(isSelfDeviding(a));
    }
}