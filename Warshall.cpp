#include <iostream>
#include <algorithm>
#include <cstdlib>

#define MAX 20

using namespace std;

bool adj_mat[MAX][MAX], path_mat[MAX][MAX];
int N;

void input() {
	int node_chk;
	
	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
				cin >> node_chk;
			if (node_chk)
				adj_mat[i][j] = 1 ;
			else
				adj_mat[i][j] = 0;
		}
	}
}

void display() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << path_mat[i][j] << " ";
		}
		cout << endl;
	}
}

void warshall() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			path_mat[i][j] = adj_mat[i][j];
		}
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				path_mat[i][j] = path_mat[i][j] || (path_mat[i][k] && path_mat[k][j]);
			}
		}
	}
}

int main() {
	input();
	warshall();
	display();	
	return 0;
}
