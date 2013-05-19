#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <sys/time.h>
#include <queue>
#define MAX 20

using namespace std;

int adj_mat[MAX][MAX];
int connected[MAX];
int N;

void input() {
	int node_chk;
	
	cout << "Enter Number Of Vertices: ";
	cin >> N;
	cout << "Enter Adjacency Matrix Of Directed Graph: " << endl;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j)
				node_chk = 1;
			else {
				cout << "Is there An Edge Between " << i << " And " << j << "?(1/0): ";
				cin >> node_chk;
			}
			if (node_chk)
				adj_mat[i][j] = 1;
			else
				adj_mat[i][j] = 0;
		}
	}
}

int main() {
	int start, current;
	queue<int> q;

	for (int i = 1; i <= N; i++)
		connected[i] = 0;
	
	input();
	
	cout << "Enter The Starting Node: ";
	cin >> start;
	
	if (start > N || start < 1) {
		cout << "Invalid Vertex" << endl;
		return 1;
	}

	q.push(start);
	connected[start] = 1;

	while(!q.empty()) {
		current = q.front();
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (adj_mat[current][i]) {
				if (!connected[i]) {
					connected[i] = 1;
					q.push(i);
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (connected[i])
			cout << i << " ";
	}
	cout << "Are The Nodes Reachable Starting From " << start << endl;
	
	return 0;
}
