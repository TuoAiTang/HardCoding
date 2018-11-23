import java.util.*;
class test399{
	public static void main(String[] args) {
		lc399_UnionSet_Version helper = new lc399_UnionSet_Version();
		String [][] equ = {{"a", "b"}, {"e", "f"}, {"b", "e"}};
		String [][] query = {{"b", "a"}, {"a", "f"}, {"a", "c"}, {"f", "e"}};
		double [] ratio = {3.4, 1.4, 2.3};
		double [] ans = helper.calcEquation(equ, ratio, query);

		for(double d : ans)
			System.out.println(d);
	}	
}