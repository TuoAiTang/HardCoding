import java.util.*;
class test943{
	public static void main(String[] args) {
		String [] A = {"catg","ctaagt","gcta","ttca","atgcatc"};
		lc943_DFS_Pruning helper = new lc943_DFS_Pruning();
		String ans = helper.shortestSuperstring(A);
		System.out.println(ans);
	}
}