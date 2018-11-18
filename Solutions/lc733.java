class lc733{
	public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        int m = image.length;
        int n = image[0].length;
        int orgColor = image[sr][sc];
        if(orgColor == newColor) return image;
        floodFill(image, m, n, sr, sc, orgColor, newColor);
        return image;
    }

    private void floodFill(int[][] image, int m, int n, int x, int y, int orgColor, int newColor){
    	if(x < 0 || x >= m || y < 0 || y >= n)
    		return;
    	if(image[x][y] != orgColor) return;

    	image[x][y] = newColor;

    	floodFill(image, m, n, x + 1, y, orgColor, newColor);
    	floodFill(image, m, n, x - 1, y, orgColor, newColor);
    	floodFill(image, m, n, x, y + 1, orgColor, newColor);
    	floodFill(image, m, n, x, y - 1, orgColor, newColor);
    }
}	

	