#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

#define MAX 20

using namespace std;

int coeff[MAX+1][MAX+2], N, M;

int main() {
	cin >> N >> M;
	coeff[0][0] = 1;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= i; j++) {
				if (j == 0 || j == i)
					coeff[i][j] = 1;
				else
					coeff[i][j] = coeff[i-1][j-1] + coeff[i-1][j];
		}
	}
	/*
	for (int i = 0; i <= N; i++) {
		for (int p = 1; p <= N-i; p++)
			cout << "  ";
		for (int j = 0; j <= i; j++) {
			cout << coeff[i][j] << "   ";
		}
		cout << endl;
	}
	*/
	cout << coeff[N][M] << endl;
	return 0;
}
