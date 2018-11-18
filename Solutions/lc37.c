#include<stdio.h>
#include<stdlib.h>
//Author: TuoAiTang

#define Box(i, j) ((i) / 3 * 3 + (j) / 3)
//i, x, row, vertical, top->down; 
//j, y, col, horizontal, left->right;

int** initMatrix(){
	int** matrix = (int**)calloc(9, sizeof(int*));
	for (int i = 0; i < 9; ++i)
		matrix[i] = (int*)calloc(10, sizeof(int));
	return matrix;
}
bool fill(char** board, int x, int y, int** rows, int** cols, int** boxes){
	if(x == 9) return true;
	int ny = (y + 1) % 9;
	int nx = (ny == 0) ? x + 1 : x;
	if(board[x][y] != '.') return fill(board, nx, ny, rows, cols, boxes);

	for (int i = 1; i <= 9; ++i)
	{
		if(!cols[y][i] && !rows[x][i] && !boxes[Box(x, y)][i]){
			rows[x][i] = 1;
			cols[y][i] = 1;
			boxes[Box(x, y)][i] = 1;
			board[x][y] = i + '0';
			if(fill(board, nx, ny, rows, cols, boxes))
				return true;
			board[x][y] = '.';
			rows[x][i] = 0;
			cols[y][i] = 0;
			boxes[Box(x, y)][i] = 0;
		}
	}
	return false;
}

void solveSudoku(char** board, int boardRowSize, int boardColSize) {
	int** rows = initMatrix();
	int** cols = initMatrix();
	int** boxes = initMatrix();

	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			char c = board[i][j];
			if(c != '.'){
				int n = c - '0';
				rows[i][n] = 1;
				cols[j][n] = 1;
				int box = Box(i, j);
				boxes[box][n] = 1;
			}
		}
	}
	fill(board, 0, 0, rows, cols, boxes);
    for(int i = 0; i < 9; i++){
        free(rows[i]);
        free(cols[i]);
        free(boxes[i]);
    }
    free(rows);
    free(cols);
    free(boxes);
}

int main(int argc, char const *argv[])
{
	printf("%d\n", 5 / 3 * 3);
	return 0;
}