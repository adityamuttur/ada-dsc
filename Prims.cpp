#include <iostream>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAX 1000

using namespace std;

struct vertex {
	int name;
	int from;
	int distance;
}vertices[MAX];

int adjMat[MAX][MAX], N, start;

int mySort(const void *a, const void *b) {
	return (*(vertex*)a).distance - (*(vertex*)b).distance;
}

int main() {
	int chk, cur, len;

	cin >> N;
	len = N;
	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			if (i == j)
				continue;
			cout << "Is there a vertex form " << i+1 << " to " << j+1 << "?(size/0) ";
			cin >> chk;
			if (chk) {
				adjMat[i][j] = chk;
			}
			else
				adjMat[i][j] = -1;
		}
		vertices[i].name = i+1;
		vertices[i].from = 0;
		vertices[i].distance = INT_MAX;
	}
	
	cout << "Enter Starting Vertex: ";
	cin >> start;

	for (int i = 0; i < N; i++)
		if (vertices[i].name == start) {
			cur = vertices[i].name-1;
			swap(vertices[i], vertices[--N]);
			break;
		}
	do {
		for (int i = 0; i < N; i++) {
			if (adjMat[cur][i] != -1)
				for (int j = 0; j < N; j++)
					if (i+1 == vertices[j].name)
						if (vertices[j].distance > adjMat[cur][i]) {
							vertices[j].distance = adjMat[cur][i];
							vertices[j].from = cur+1;
						}
		}
		//cout << N << endl;;
		qsort(vertices, N, sizeof(vertices[0]), mySort);
		cur = vertices[0].name-1;
		swap(vertices[0], vertices[--N]);
		cout << vertices[i].name << "  " << vertices[i].from << "  " << vertices[i].distance << endl;
	}while(N >= 0);
	
	for (int i = 0; i < len; i++)
		cout << vertices[i].name << "  " << vertices[i].from << "  " << vertices[i].distance << endl;
	
	return 0;
}
