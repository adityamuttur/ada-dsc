#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define SIZE 100000

struct edge {
    int x;
    int y;
    int cost;
};

//Sort by Cost
bool operator < (edge a, edge b) {
    return a.cost < b.cost;
}

vector < edge > v, ans;
int connected[SIZE], N, minCost;

int main() {
    int M;
    edge temp;
    
    cin >> N >> M;

    //Input 'M' Edges. Vertices from 1..N
    for (int i = 0; i < M; i++) {
        cin >> temp.x >> temp.y >> temp.cost;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    
    //connectivity of vertices. Edges are numbered from 1...N
    for (int i = 1; i <= N; i++)
        connected[i] = i;
    
    minCost = 0;
    for (int i = 0; i < v.size(); i++) {
        temp = v[i];

        //Check Connectivity Of Nodes. Can use other better algos
        if (connected[temp.x] == connected[temp.y])
            continue;
        int t1 = connected[temp.x];
        int t2 = connected[temp.y];
        for (int j = 1; j <= N; j++)
            if (connected[j] == t2)
                connected[j] =  t1;
        minCost += temp.cost;
        
        //Add edge To Solution
        ans.push_back(temp);
    }
    
    cout << "Minimum Cost: " << minCost << endl << "Edges Are: " << endl;  
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].x << " " << ans[i].y << " " << ans[i].cost << endl;

    return 0;
}
