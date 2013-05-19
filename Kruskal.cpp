#include <iostream>
#include <algorithm>

#define MAX 1000

using namespace std;

struct edge {
	int a;
	int b;
	int edgeWeight;
}a[MAX];

int nVertices, connected[MAX], N;
bool used[MAX];

int compare(const void *a, const void *b) {
	return (*(edge *)a).edgeWeight - (*(edge *)b).edgeWeight;
}

int main() {
	int temp, total = 0;

	cin >> nVertices;
	for (int i = 1; i <= nVertices; i++)
		connected[i] = i;

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> a[i].a >> a[i].b >> a[i].edgeWeight;
	
	qsort(a+1, N, sizeof(a[0]), compare);
	
	for (int i = 1; i <= N; i++) {
		if (connected[a[i].a] != connected[a[i].b]) {
			temp = connected[a[i].b];
			for (int j = 1; j <= nVertices; j++)
				if (connected[j] == temp)
					connected[j] = connected[a[i].a];
			used[i] = true;
		}
		else
			used[i] = false;
	}

	for (int i = 1; i <= N; i++)
		if (used[i]) {
			cout << a[i].a << "  " << a[i].b << "  " << a[i].edgeWeight << "  " << endl;
			total += a[i].edgeWeight;
		}
	cout << "Total Weight = " << total << endl;
	
	return 0;
}
