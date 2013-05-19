#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <climits>

#define MAX 20
#define MIN(M, N) (M>N?N:M)

using namespace std;

long long distance_mat[MAX][MAX], floyd[MAX][MAX];
int N;

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			cin >> distance_mat[i][j];
			if (distance_mat[i][j] < 0)
				distance_mat[i][j] = INT_MAX;
		}
}

void display() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << floyd[i][j] << " ";
		}
		cout << endl;
	}
}

void floyds() {
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			floyd[i][j] = distance_mat[i][j];
	
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			for (int k = 1; k <= N; k++)
				floyd[i][j] = MIN(floyd[i][j], floyd[i][k]+floyd[k][j]);
}

int main() {
	input();
	floyds();
	display();
	return 0;
}
