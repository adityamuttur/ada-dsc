#include <iostream>
#include <stdint.h>

using namespace std;

int n;
uint64_t edges[1000][1000], solutions[1000];
bool done[1000];

void dijkstra(int start) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			
			if (solutions[i] + start[start][]);
		}
	}

}
int main() {
	int choice;
	
	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << "Is There An Edge Between " << i << " And " << j << ": ";
			cin >> choice;
			if (choice)
				cin >> edges[i][j];
			else
				edge[i][j] = INT_MAX;

		}
		solutions[i] = 0;
	}
	
	cin >> start;
	
	dijkstra(start);
	
	for (int i = 1; i <= N; i++)
		cin >> edges[i].a >> edges[i].b >> edges[i].edgeWeight;
	
	return 0;
}
