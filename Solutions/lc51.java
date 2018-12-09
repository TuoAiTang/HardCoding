//2ms beats 100%
import java.util.*; 
class lc51 {
	private char [][] board;
	private boolean [] cols;
	private boolean [] diag1;
	private boolean [] diag2;
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> ans = new ArrayList<>();
        board = new char[n][n];
        for(char [] b : board)
        	Arrays.fill(b, '.');
        cols = new boolean[n];
        diag1 = new boolean[2 * n - 1];
        diag2 = new boolean[2 * n - 1];

        nqueens(n, 0, ans);

        return ans;
    }

    private boolean available(int x, int y, int n){
    	return !cols[y] && !diag1[x + y] && !diag2[y - x + n - 1];
    }

    private void updateBoard(int n, int x, int y, boolean is_put){
    	cols[y] = is_put;
    	diag1[x + y] = is_put;
    	diag2[y - x + n - 1] = is_put;
    	board[x][y] = is_put ? 'Q' : '.';
    }

    private void nqueens(int n, int x, List<List<String>> ans){
    	if(x == n){
    		List<String> item = new ArrayList<>();
    		for(char [] s: board)
    			item.add(new String(s));
    		ans.add(item);
    		return;
    	}

    	for(int i = 0; i < n; i++){
    		if(available(x, i, n)){
    			updateBoard(n, x, i, true);
    			nqueens(n, x + 1, ans);
    			updateBoard(n, x, i, false);
    		}
    	}
    }
}

