#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <queue>
#include <vector>

using namespace std;

#define SIZE 1000

const int INF = 2 << 10;

int N, minCostTo[SIZE], adjMat[SIZE][SIZE];
vector < int  > shortestPath[SIZE];
bool visited[SIZE];


void dijkstra(int source) {
    priority_queue < int, vector < int >, greater < int > > q;
    int fromVertex;
    
    q.push(source);
    while (!q.empty()) {
        fromVertex = q.top();
        q.pop();
        if (visited[fromVertex])
            continue;
        visited[fromVertex] = 1;
        for (int i = 0; i < N; i++) {
            if (i == fromVertex)
                continue;

            if (minCostTo[fromVertex] + adjMat[fromVertex][i] < minCost[i]) {
                minCostTo[i] = minCost[fromVertex] + adjMat[fromVertex][i];
                shortestPath[i] = SP[fromVertex];
                shortestPath[i].push_back(i);
                q.push(i);
            }
        }
    }
}

int main() {
    int source;
    
    cin >> N;
    //cout << "Enter Adjacency Matrix: ";
    for (int i  = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> adjMat[i][j];
            if (adjMat[i][j] == -1)
                adjMat[i][j] = INF;
        }
        minCostTo[i] = INF;
    }
    
    //cout << "Enter Source: ";
    cin >> source;

    memset(visited, 0, SIZE*sizeof(bool));
    shortestPath[source].push_back(source);
    minCostTo[source] = 0;

    dijkstra(source);
    
    for (int i = 0; i < N; i++) {
        if (i == source)
            continue;
        cout << "Source To " << i << ": ";
        for (int j = 0; j < shortestPath[i].size(); j++) {
            cout << shortestPath[i][j];
            if (shortestPath[i][j] != i)
                cout << "->";
        }
        cout << ".  MinCost: " << minCostTo[i] << endl;
    }
    
    return 0;
}
