import java.util.*;
class lc89 {
	//1ms beats 66.49%
    public List<Integer> grayCode(int n) { 	
        if(n == 0){
        	List<Integer> ans = new ArrayList<>();
        	ans.add(0);
        	return ans;
        }

        List<Integer> ans = grayCode(n - 1);
        int addNum = 1 << (n - 1);
        for(int i = ans.size() - 1; i >= 0; i--)
        	ans.add(addNum + ans.get(i));

        return ans;    }
}