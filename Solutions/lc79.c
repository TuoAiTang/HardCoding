

bool search(char** board, int boardRowSize, int boardColSize, char* word, int d, int x, int y){
	if(x == boardRowSize || x < 0 || y == boardColSize || y < 0 || word[d] != board[x][y])
		return false;
	if(d == strlen(word) - 1)
		return true;
	char c = board[x][y];
	board[x][y] = 0;
	bool found = search(board, boardRowSize, boardColSize, word, d + 1, x + 1, y)
		|| search(board, boardRowSize, boardColSize, word, d + 1, x - 1, y)
		|| search(board, boardRowSize, boardColSize, word, d + 1, x, y + 1)
		|| search(board, boardRowSize, boardColSize, word, d + 1, x, y - 1);

	board[x][y] = c;
	return found;
}

bool exist(char** board, int boardRowSize, int boardColSize, char* word) {
	if(boardRowSize == 0) return false;
    for(int i = 0; i < boardRowSize; i++){
    	for (int j = 0; j < boardColSize; ++j)
	    	if(search(board, boardRowSize, boardColSize, word, 0, i, j))
	    		return true;
	return false;
}