#include <iostream>
#include <algorithm>

using namespace std;

#define SIZE 1000

bool queens[SIZE][SIZE];
int N, countSolutions;

void printQueens() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << (queens[i][j] == 1 ? "Q " : ". ");
        cout << endl;
    }
    cout << endl;
}

bool isValidPosition(int row, int col) {
    for (int i = 0; i < row; i++)
        if (queens[i][col])
            return 0;
    for (int i = row-1, j = col-1; i >= 0 && j >= 0; j--, i--)
        if (queens[i][j])
            return 0;
    for (int i = row-1, j = col+1; i >= 0 && j < N; j++, i--)
        if (queens[i][j])
            return 0;
    return 1;
}

void solveForQueens(int row) {
    if (row == N) {
        printQueens();
        countSolutions++;
        return;
    }
    for (int i = 0; i < N; i++) {
        queens[row][i] = 1;
        if (isValidPosition(row, i))
            solveForQueens(row+1);
        queens[row][i] = 0;
    }
}

int main() {
    cin >> N;
    
    countSolutions = 0;
    solveForQueens(0);
    cout << "Total Number Of Solutions: " << countSolutions << endl;

    return 0;
}
