#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <sys/time.h>
#include <stack>

#define MAX 20

using namespace std;

int a[MAX][MAX];
int visited[MAX];
int N, flag, inStack[MAX];
stack<int> s;

void DFS(int v) {
	visited[v] = 1;
	for (int i = 1; i <= N; i++) {
		if (a[v][i]) {
			if (!inStack[i]) {
				if (!visited[i]) {
					inStack[i] = 1;
					DFS(i);
				}
			}
			else {
				flag = 0;
				return;
			}
		}
	}
	inStack[v] = 0;
	s.push(v);
}

void input() {
	int node_chk;
	
	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> node_chk;
			if (node_chk)
				a[i][j] = 1;
			else
				a[i][j] = 0;
		}
	}
}

int main() {
	int start;

	input();
	
	for (int i = 1; i <= MAX; i++)
		inStack[i] = 0;
	
	cin >> start;
	flag = 1;
	inStack[start] = 1;
	
	DFS(start);
	
	if (!flag) {
		cout << "Not A DAG!!!" << endl;
		return -1;
	}
	while(!s.empty()) {
		cout << s.top() << "  ";
		s.pop();
	}
	cout << endl;

	return 0;
}
