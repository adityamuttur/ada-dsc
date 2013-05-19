#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <sys/time.h>

#define MAX 20

using namespace std;

int a[MAX][MAX];
int visited[MAX];
int N;

void DFS(int v) {
	visited[v] = 1;
	for (int i = 1; i <= N; i++)
		if (a[v][i])
			if (!visited[i])
				DFS(i);
}

void input() {
	int node_chk;
	
	cout << "Enter Number Of Vertices: ";
	cin >> N;
	cout << "Enter Adjacency Matrix: " << endl;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j)
				node_chk = 1;
			else {
				cout << "Is there An Edge Between " << i << " And " << j << "?(1/0): ";
				cin >> node_chk;;
			}
			if (node_chk)
				a[i][j] = 1;
			else
				a[i][j] = 0;
		}
	}
}

int main() {
	int flag = 1, start;

	for (int i = 1; i <= N; i++)
		visited[i]  = 0;
	
	input();
	
	cout << "Enter The Starting Node: ";
	cin >> start;
	
	DFS(start);

	for (int i = 1; i <= N; i++) {
		cout << visited[i] << " ";
		if (!visited[i]) {
			flag = 0;
			break;
		}
	}
	
	if (flag)
		cout << "Graph Connected" << endl;
	else
		cout << "Not Connected" << endl;
	
	return 0;
}
