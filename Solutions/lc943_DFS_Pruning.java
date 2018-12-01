//566ms beats 5.94%
//Time: O(n!)
//Space: O(n^2) for pre-process + O(n) depth of recursion
import java.util.*;
class lc943_DFS_Pruning {
	private int [] best_path;
	private int best_len;
    public String shortestSuperstring(String[] A) {
        int n = A.length;

        //pre-process to caculate the offset
        int [][] os = new int[n][n];
        for(int i = 0; i < n; i++){
        	for(int j = 0; j < n; j++){
        		int li = A[i].length();
        		int lj = A[j].length();
        		os[i][j] = lj;
        		for(int k = 1; k <= Math.min(li, lj); k++){
        			//k character in the tail of i, while the head of j
        			if(A[i].substring(li - k).equals(A[j].substring(0, k)))
        				os[i][j] = lj - k;
        		}
        	}
        }

        int [] path = new int[n];       
		best_len = Integer.MAX_VALUE;
        dfs(A, 0, 0, 0, path, os);

        for(int i = 0; i < n; i++){
        	System.out.println("best_path[" + i + "] : " + best_path[i]);
        	System.out.println("path[" + i + "] : " + path[i]);
        }

        String ans = A[best_path[0]];
        for(int k = 1; k < n; k++){
        	int i = best_path[k - 1];
        	int j = best_path[k];
        	ans += A[j].substring(A[j].length() - os[i][j]);
        }
        return ans;
    }
    //O(n!)
    private void dfs(String [] A, int d, int used, int cur_len, int [] path, int [][] os){
    	if(cur_len >= best_len) return;	//important pruning
    	if(d == A.length){
    		best_path = Arrays.copyOf(path, path.length);
    		best_len = cur_len;
    		return;
    	}
    	for(int i = 0; i < A.length; i++){
    		if((used & (1 << i)) != 0) continue;
    		path[d] = i;
    		dfs(A, 
    			d + 1, 
    			used | (1 << i),
    			d == 0 ? A[i].length() : cur_len + os[path[d - 1]][i],
    			path,
    			os);
    	}
    }
}