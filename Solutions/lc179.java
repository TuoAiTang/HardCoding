import java.util.*;
public class lc179{
 	public String largestNumber(int[] nums) {
        if(nums.length == 0) return "0";

        String [] strs = new String[nums.length];
        for(int i = 0; i < nums.length; i++)
        	strs[i] = String.valueOf(nums[i]);

        Arrays.sort(strs, new Comparator<String>(){
        	public int compare(String a, String b){
        		return (b + a).compareTo(a + b);
        	}
        });

        if(strs[0].equals("0")) return "0";
        String ans = "";
        for (String str : strs) {
        	ans += str;
        }
        return ans;
    }
}