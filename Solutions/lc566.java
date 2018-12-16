class lc566 {
	//7ms beats 24.09
    public int[][] matrixReshape(int[][] nums, int r, int c) {
        if(nums == null) return nums;
        int m = nums.length;
        int n = nums[0].length;

        if(m * n != r * c) return nums;
        int [][] ans = new int[r][c];

        for(int i = 0; i < m * n; i++){
        	int org_x = i / n;
        	int org_y = i % n;
        	int new_x = i / c;
        	int new_y = i % c;

        	ans[new_x][new_y] = nums[org_x][org_y];
        }
        return ans;
    }
}