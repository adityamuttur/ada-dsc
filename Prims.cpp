#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define SIZE 100000
using namespace std;

typedef pair < int, int > endPoints;
typedef pair < int, endPoints> path;

int N, M, startVertex;
vector < path > V[SIZE], MST;
bool visited[SIZE];

int prims() {
    int minimumValue = 0, edgeCost, fromVertex, toVertex;
    priority_queue < path, vector < path >, greater < path > > Q;
	path temp;

    memset(visited, 0, SIZE*sizeof(bool));	
    Q.push(path(-1, endPoints(-1, -1)));
	while (!Q.empty()) {
		temp = Q.top();
        Q.pop();
        edgeCost   = temp.first == -1 ? 0 : temp.first;
		fromVertex = temp.second.first == -1 ? startVertex : temp.second.first;
        if (visited[fromVertex])
			continue;
        if (temp.second.first != -1)
            MST.push_back(temp);
		minimumValue += edgeCost;
		visited[fromVertex] = 1;
        for (int j = 0; j < V[fromVertex].size(); j++) {
            toVertex = V[fromVertex][j].second.second;
			edgeCost = V[fromVertex][j].first;
			if (!visited[toVertex])
				Q.push(path(edgeCost, endPoints(toVertex, fromVertex)));
		}
	}
    return minimumValue;
}
int main() {
    int x, y, cost; 
    
    //cout << "Enter Number Of Vertices And Number Of Edges: ";
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        //cout << "Enter Start Vertex End Vertex Cost: ";
        cin >> x >> y >> cost;
        if (i == 0)
            startVertex = x;
        V[x].push_back(path(cost, endPoints(x, y)));
        V[y].push_back(path(cost, endPoints(y, x)));
    }
    cout << "Minimum Cost: " << prims() << endl;
    for (vector < path > :: iterator p = MST.begin(); p != MST.end(); p++)
        cout << (*p).second.first << "<->" << (*p).second.second << " " << (*p).first << endl;
    return 0;
}
