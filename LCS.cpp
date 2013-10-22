// A Program using Dynamic Programming to find
// Longest Common Subsequence of 2 strings

#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

#define SIZE 1000

void create_lcs(int b[SIZE][SIZE], char *X, int i, int j, char lcs[SIZE]) {

	if (i == 0 || j == 0)
		return;
	if (b[i][j] == 1) {
		char temp[2] = {X[i-1], '\0'};
		strcat(lcs, temp);
		create_lcs(b, X, i-1, j-1, lcs);
	}
	else if (b[i][j] == 0)
		create_lcs(b, X, i-1, j, lcs);
	else
		create_lcs(b, X, i, j-1, lcs);
}

char* get_lcs(char *X, int m, char *Y, int n, char lcs[SIZE]) {

	int b[SIZE][SIZE], c[SIZE][SIZE];

	memset(b, 0, SIZE*SIZE*sizeof(int));
	memset(c, 0, SIZE*SIZE*sizeof(int));

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			// If the last character of both strings
			// is the same then the LCS is gotten by
			// appending this character to the LCS of
			// X[0..m-2] and Y[0..n-2]. Thus the value
			// of c[][] is set and the value of b is 
			// a flag telling that X[i] = Y[j]
			if (X[i-1] == Y[j-1]) {
				c[i][j] = c[i-1][j-1] + 1;
				b[i][j] = 1;
			}
			// If the last characters are not equal
			// then the max length substring is the
			// longer of LCS X[0..m-1] and Y[0..n-2]
			// and X[0..m-2] and Y[0..n-1]. Based on
			// which is longer, set b[][] and c[][]
			else if (c[i-1][j] >= c[i][j-1]) {
				c[i][j] = c[i-1][j];
				b[i][j] = 0;
			}
			else {
				c[i][j] = c[i][j-1];
				b[i][j] = -1;
			}
		}
	}
	lcs[0] = '\0';
	create_lcs(b, X, m, n, lcs);
	reverse(lcs, lcs+strlen(lcs));

	return lcs;
}

int main() {

	char X[SIZE], Y[SIZE], LCS[SIZE];
	int m, n;

	scanf("%s %s", X, Y);
	m = strlen(X);
	n = strlen(Y);
	cout << get_lcs(X, m, Y, n, LCS) << endl;

	return 0;
}