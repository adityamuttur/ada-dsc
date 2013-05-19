#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>

#define MAX 1000
using namespace std;

int N, arr[MAX];
bool chessBoard[MAX][MAX];

inline bool isValid(int curRow, int curCol) {
	//Check if all the elements of the given row are zero, except when column = current column
	for (int i = 0; i < N; i++)
		if (i != curCol && chessBoard[curRow][i])
			return 0;
	
	//Check if all the elements of the given column are zero, except when row = current row
	for (int i = 0; i < N; i++)
		if (i != curRow && chessBoard[i][curCol])
			return 0;
	
	//Check along 1st diagonal downwards
	for (int i = curRow+1, j = curCol+1; i < N && j < N; i++, j++)
		if (chessBoard[i][j])
			return 0;
	
	//Check along 1st diagonal upwards
	for (int i = curRow-1, j = curCol-1; i >= 0 && j >= 0; i--, j--)
		if (chessBoard[i][j])
			return 0;
	
	//Check along 2nd diagonal downwards
	for (int i = curRow-1, j = curCol+1; i >= 0 && j < N; i--, j++)
		if (chessBoard[i][j])
			return 0;
	
	//Check along 2nd diagonal upwards
	for (int i = curRow+1, j = curCol-1; i < N && j >= 0; i++, j--)
		if (chessBoard[i][j])
			return 0;
	
	return 1;
}

int solveForQueens(int Row) {
	if (Row == N)
		return 1;
	for (int i = 0; i < N; i++) {
		chessBoard[Row][i] = 1;
		if (isValid(Row, i))
			if (solveForQueens(Row+1))
				return 1;
		chessBoard[Row][i] = 0;
	}
	return 0;
}

int main() {
	cin >> N;
	memset(chessBoard, 0, MAX*MAX);
	
	if (solveForQueens(0)) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (chessBoard[i][j])
					cout << "Q ";
				else
					cout << ". ";
			}
			cout << endl;
		}
	}
	else
		cout << "No Solution" << endl;
	return 0;
}
