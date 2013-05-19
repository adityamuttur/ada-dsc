#include <iostream>
#include <cstdlib>
#include <cstdio>
#define MAX 10000 

using namespace std;

int W, N, X, Y, counter, temp, V[MAX][MAX], wt[MAX], val[MAX], arr[MAX];
bool keep[MAX][MAX];

int main() {
	//cout << "Enter The Number Of Items And Max Weight Of Knapsack
    cin >> N >> W;
	
    //Enter The Weight And Value Of Each Of The "N" Items
	for (int i = 1; i <= N; i++)
		cin >> wt[i] >> val[i];
	for (int i = 0; i <= N; i++) {
		for (int j = 1; j <= W; j++ ) {
			if (i == 0) {
				V[i][j] = 0;
				keep[i][j] = 0;
			}
			else {
				temp = val[i];
				if (j - wt[i] > 0)
					temp += V[i-1][j-wt[i]];
				if (wt[i] <= j && temp > V[i-1][j]) {
					keep[i][j] = 1;
					V[i][j] = temp;
				}
				else {
					keep[i][j] = 0;
					V[i][j] = V[i-1][j];
				}
			}
		}
	}
	X = N;
	Y = W;
	counter = 0;
	
    /*Value Matrix
	for (int i = 0; i <= N; i++) {
		for (int j = 1; j <= W; j++)
			printf("%-6d", V[i][j]);
		cout << endl;
	}
	*/

	while (Y > 0 && X > 0) {
		if (keep[X][Y]) {
			arr[counter++] = X;
			Y -= wt[X];
			X--;
		}
		else
			X--;
	}
	if (!counter)
		cout << "No Solution For Knapsack." << endl;
	else {
		for (int i = counter-1; i >= 0; i--) {
			cout << arr[i];
			if (i != 0)
				cout << ", ";
		}
		cout << " Are The Element(s) Of The Knapsack. Max Weight = " << V[N][W] << endl;
	}
	return 0;
}
