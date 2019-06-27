import java.util.*;
class testJ{	
	public static void main(String[] args) {
		int [] c = new int [1];
		Arrays.fill(c, 1);
		System.out.println(hIndex(c));
	}

	public static int hIndex(int[] citations) {
        int n = citations.length;
        int [] bucket = new int [n + 1];
        for(int c : citations)
            bucket[Math.min(c, n)]++;
        int sum = 0;
        for(int i = n; i >= 0; i--){
            sum += bucket[i];
            if(sum >= i)
                return i;
        }
        return 0;
    }
}

