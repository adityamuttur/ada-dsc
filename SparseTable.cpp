// To find the largest and smallest element in a give L, R range
// in an array of elememts

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

#define SIZE 1002

void min_sparse_table(int b[SIZE][SIZE], int n) {
	int y, k;

	k = log2(n);
	for(int i = 1; i <= k; i++) {
		y = (int)(pow(2.0, (double)(i)));
		for(int j = 0; j <= n-y; j++)
			b[i][j] = min(b[i-1][j] , b[i-1][j+(y/2)]);
	}
}

inline int min_query(int b[SIZE][SIZE], int l, int r) {
	int k, x;

	k = log2(r - l + 1);
	x = (int)(pow(2.0,(double)(k))) - 1;

	return min(b[k][l],b[k][r-x]);
}

void max_sparse_table(int c[SIZE][SIZE], int n) {
	int y, k;

	k = log2(n);
	for(int i = 1; i <= k; i++) {
		y = (int) (pow(2.0,(double)(i)));
		for(int j = 0; j <= n-y; j++)
			c[i][j] = max(c[i-1][j] , c[i-1][j+(y/2)]);
	}
}

inline int max_query(int c[SIZE][SIZE], int l, int r) {
	int k, x;

	k = log2(r - l + 1);
	x = (int)(pow(2.0, (double)(k))) - 1;

	return max(c[k][l], c[k][r-x]);
}

int main() {
	int N, b[SIZE][SIZE],c[SIZE][SIZE];
	int Q, L, R;

	printf("Enter N (max 1000): ");
	scanf("%d", &N);
	
	printf("Enter elements:\n");
	for(int i = 0; i < N; i++) {
		scanf("%d", &b[0][i]);
		c[0][i] = b[0][i];
	}

	min_sparse_table(b, N);
	max_sparse_table(c, N);

	printf("Enter number of L,R queries : ");
	scanf("%d", &Q);

	for(int i = 0; i < Q; i++) {
		printf("Enter L, R (1-based) : ");
		scanf("%d %d", &L, &R);

		printf("Minimum in range (%d, %d) = %d\n\n",
			L-1, R-1, min_query(b, L-1, R-1));
		printf("Maximum in range (%d, %d) = %d\n\n",
			L-1, R-1, max_query(c, L-1, R-1));
	}

	return 0;
}