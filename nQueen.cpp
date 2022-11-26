
#include <bits/stdc++.h>
#define N 8
using namespace std;

void printSolution(int board[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << " " << board[i][j] << " ";
		printf("\n");
	}
}

bool isSafe(int board[N][N], int row, int col)
{
int x = row;
    int y = col;
    while(y>=0){
        if(board[x][y] == 1){
            return false;
            
        }
        y--;
    }
    
    x = row;
    y = col;
    while(x>=0 && y>=0){
        if(board[x][y] == 1){
            return false;
           
        }
         y--;
            x--;
    }
    
    
    x = row;
    y = col;
    while(x<col && y>=0){
        if(board[x][y] == 1)
            return false;
        y--;
        x++;
    }
    return true;
}

bool solveNQUtil(int board[N][N], int col)
{

	if (col >= N)
		return true;

	for (int i = 0; i < N; i++) {

		if (isSafe(board, i, col)) {

			board[i][col] = 1;
			if (solveNQUtil(board, col + 1))
				return true;

			board[i][col] = 0; // BACKTRACK
		}
	}

	return false;
}


bool solveNQ()
{
	int board[N][N] = { { 0, 0, 0, 0, 0, 0, 0, 0},
						{ 0, 0, 0, 0, 0, 0, 0, 0},
						{ 0, 0, 0, 0, 0, 0, 0, 0},
						{ 0, 0, 0, 0, 0, 0, 0, 0},
						{ 0, 0, 0, 0, 0, 0, 0, 0},
	                    { 0, 0, 0, 0, 0, 0, 0, 0},
	                    { 0, 0, 0, 0, 0, 0, 0, 0},
	                    { 0, 0, 0, 0, 0, 0, 0, 0}};

	if (solveNQUtil(board, 0) == false) {
		cout << "Solution does not exist";
		return false;
	}

	printSolution(board);
	return true;
}

int main()
{
	solveNQ();
	return 0;
}
