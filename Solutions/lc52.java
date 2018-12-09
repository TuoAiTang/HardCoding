//1ms beats 99.67%
import java.util.*;
class lc52 {
	private boolean [] cols;
	private boolean [] diag1;
	private boolean [] diag2;
	private int ans;
    public int totalNQueens(int n) {
        ans = 0;
        cols = new boolean[n];
        diag1 = new boolean[2 * n - 1];
        diag2 = new boolean[2 * n - 1];

        nqueens(n, 0);
        return ans;
    }

    private boolean available(int x, int y, int n){
    	return !cols[y] && !diag1[x + y] && !diag2[y - x + n - 1];
    }

    private void updateBoard(int n, int x, int y, boolean is_put){
    	cols[y] = is_put;
    	diag1[x + y] = is_put;
    	diag2[y - x + n - 1] = is_put;
    }

    private void nqueens(int n, int x){
    	if(x == n){
    		ans++;
    		return;
    	}

    	for(int i = 0; i < n; i++){
    		if(available(x, i, n)){
    			updateBoard(n, x, i, true);
    			nqueens(n, x + 1);
    			updateBoard(n, x, i, false);
    		}
    	}
    }
}