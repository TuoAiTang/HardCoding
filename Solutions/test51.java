import java.util.*;
class test51{
	public static void main(String[] args) {
		// lc51 helper = new lc51();
		// List<List<String>> ans = helper.solveNQueens(15);
		// for(List<String> item : ans){
		// 	for(String s : item)
		// 		System.out.println(s);
		// 	System.out.println("------------");
		// }

		lc52 helper = new lc52();
		int ans = helper.totalNQueens(15);
		System.out.println("Total: " + ans);

		
	}
}