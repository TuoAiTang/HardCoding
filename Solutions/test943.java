import java.util.*;
class test943{
	public static void main(String[] args) {
		String [] A = {"catg","ctaagt","gcta","ttca","atgcatc"};
		lc943_DP helper = new lc943_DP();
		String ans = helper.shortestSuperstring(A);
		System.out.println(ans);
	}
}