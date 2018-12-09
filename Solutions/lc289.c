int min(int a, int b){
	return a < b ? a : b;
}
int max(int a, int b){
	return a > b ? a : b;
}

int countLiveCells(int x, int y, int** board, int m, int n){
	int count = 0;
	for(int i = max(x - 1, 0); i <= min(m - 1, x + 1); i++){
		for(int j = max(y - 1, 0); j <= min(n - 1, y + 1); j++){
			if(i == x && j == y) continue;
			count += (board[i][j] & 1);
		}
	}
	return count;
}
void gameOfLife(int** board, int boardRowSize, int *boardColSizes) {
    int m = boardRowSize;
    int n = *boardColSizes;

    for(int i = 0; i < m; i++){
    	for(int j = 0; j < n; j++){
    		int count = countLiveCells(i, j, board, m, n);
    		if(board[i][j] == 1){
    			if(count == 2 || count == 3){
    				board[i][j] += 2;	//3 >> 1 = 1; 1 >> 1 = 0;
    			}
    		}
    		else if(count == 3)
    			board[i][j] += 2;	//2 >> 1 = 0; 0 >> 1 = 0;
    	}
    }

    for(int i = 0; i < m; i++)
    	for(int j = 0; j < n; j++)
    		board[i][j] >>= 1;
}

