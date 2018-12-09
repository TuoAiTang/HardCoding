import java.util.*;
class testJ{
	
	public static void main(String[] args) {
		String s = "leetcode";
		System.out.println(s.substring(3, 4));
	}

	private static void swap(String s1, String s2){
		String tmp = s1;
		s1 = s2;
		s2 = tmp;
	}

	static class Pair{
		int a;
		int b;
		public Pair(int a, int b){
			this.a = a;
			this.b = b;
		}
	}
}


