#include <iostream>

using namespace std;

#define SIZE 1000

int main() {
    int N, K, binCoeff[SIZE][SIZE];
    
    cin >> N >> K;
    
    binCoeff[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i)
                binCoeff[i][j] = 1;
            else
                binCoeff[i][j] = binCoeff[i-1][j-1] + binCoeff[i-1][j];
        }
    }
    
    /* Printing The Pascal Triangle 
    for (int i = 0; i <= N; i++) {
        for (int j = 1; j <= N-i; j++)
            cout << " ";
        for (int j = 0; j <= i; j++)
            cout << binCoeff[i][j] << " ";
        cout << endl;
    }
    */
    
    cout << N << "C" << K << "=" << binCoeff[N][K] << endl;
    
    return 0;
}
