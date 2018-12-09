import java.util.*;
class lc455 {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
        int r = 0;
        int ans = 0;
        for(int l = 0; l < g.length; l++){
        	while(r < s.length && g[l] > s[r])
        		r++;
        	if(r != s.length){
        		r++;
        		ans++;
        	}       	
        }
        return ans;
    }
}