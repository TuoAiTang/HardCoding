//85ms - 136ms beats 5.9% - 41.2%
class lc304{

}
class NumMatrix {
	private int [][] sums;
    public NumMatrix(int[][] matrix) {
        if(matrix == null) return;
        int m = matrix.length;
        if(m == 0) return;
        int n = matrix[0].length;

        //pre-process by dp
        sums = new int [m + 1][n + 1];
        for(int i = 1; i <= m; i++)
        	for(int j = 1; j <= n; j++){
        		sums[i][j] = matrix[i - 1][j - 1]
        				   + sums[i - 1][j]
        				   + sums[i][j - 1]
        				   - sums[i - 1][j - 1];	
        	}
    }
    
    public int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2 + 1][col2 + 1] - sums[row2 + 1][col1]
        		- sums[row1][col2 + 1] + sums[row1][col1];
    }
}
