import java.util.*;
class testJ{
	
	public static void main(String[] args) {
		String s = "12345";
		System.out.println(s.substring(3, 3).length());
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


