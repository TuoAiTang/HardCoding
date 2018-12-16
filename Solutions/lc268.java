import java.util.*;
class lc268 {
	//Solution 1: sort
	//Time: O(nlogn)
	//Runntime: 14ms beats 7.61%
    public static int missingNumber1(int[] nums) {
        Arrays.sort(nums);
        for(int i = 1; i < nums.length; i++)
            if(nums[i] != nums[i - 1] + 1)
                return nums[i - 1] + 1;
        return nums[0] == 0 ? nums[nums.length - 1] + 1 : 0;
    }

    //Solution 2: swap
	//Time: O(n)
	//Runntime: 3ms beats 23.15%
    public static int missingNumber2(int[] nums) {
        int n = nums.length;
        int tmp;
        for(int i = 0; i < n; i++){
            //place all element with value n into the nth position(based 0)
            while(nums[i] < n && nums[nums[i]] != nums[i]){
                tmp = nums[nums[i]];
                nums[nums[i]] = nums[i];
                nums[i] = tmp;
            }
        }

        for(int i = 0; i < n; i++)
            if(nums[i] != i)
                return i;
        return n; 
    }

    //Solution 3: sum
    //Time: O(n)
    //Runntime: 1ms beats 66.27%
    public static int missingNumber3(int[] nums) {
        int n = nums.length;
        int sum = n * (n + 1) / 2;
        for(int i = 0; i < n; i ++)
            sum -= nums[i];
        return sum;
    }

    //Solution 4: XOR
    //Time: O(n)
    //Runntime: 2ms beats 27.63%

    //a ^ a = 0
    //a ^ 0 = a
    //a ^ b ^ b = a
    //0 ^ 0 = 0
    public static int missingNumber4(int[] nums) {
        int n = nums.length;
        int x = 0;
        for(int i = 1; i <= n; i ++)
            x =  x ^ i ^ nums[i - 1];
        return x;
    }

    public static void main(String[] args) {
    	int [] a = {0, 4, 3, 1};
    	System.out.println(missingNumber4(a));
    }
}