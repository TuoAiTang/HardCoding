import java.util.*;
class testJ{
	
	public static void main(String[] args) {

		// List<Integer> list = new ArrayList<>();
		// list.add(1);
		// list.add(23);
		// System.out.println(list);

		// Set<List<Integer>> s = new HashSet<>();
		// s.add(list);
		// list.remove(0);
		// System.out.println(s);

		System.out.println("hello world");
	}

	private static void swap(String s1, String s2){
		String tmp = s1;
		s1 = s2;
		s2 = tmp;
	}
}

class pair{
	int a;
	int b;
	public pair(int a, int b){
		this.a = a;
		this.b = b;
	}
}