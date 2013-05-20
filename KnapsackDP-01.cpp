#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define SIZE 1000

int  V[SIZE][SIZE], N, maxWt, wt[SIZE], val[SIZE];
bool keep[SIZE][SIZE];
vector < int > items;

int main() {
    int temp;
    
    cin >> N >> maxWt;
    
    for (int i = 1; i <= N; i++)
        cin >> wt[i] >> val[i];

    memset(keep, 0, SIZE*SIZE*sizeof(bool));
    memset(V, 0, SIZE*SIZE*sizeof(int)); 
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= maxWt; j++) {
            temp = val[i];
            V[i][j] = V[i-1][j];

            if (j - wt[i] < 0)
                continue;
            
            temp += V[i-1][j - wt[i]];
            if (temp > V[i-1][j]) {
                V[i][j] = temp;
                keep[i][j] = 1;
            }
        }
    }
    
    for (int i = N, j = maxWt; i >= 0 && j >= 0; i--) {
        if (keep[i][j] == 1) {
            j -= wt[i];
            items.push_back(i);
        }
    }
    
    if (!items.empty()) {
        cout << "Maximum Value: " << V[N][maxWt] << endl;
        cout << "Items Are : ";
        for (int i = 0; i < items.size(); i++) {
            cout << items[i] << " ";
        }
        cout << endl;
    }
    else
        cout << "No Solution Is Possible" << endl;
    
    return 0;
}
