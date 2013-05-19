#include <iostream>
#include <vector>
#include <cstdlib>

#define MAX 10000
#define isNegative(i) (i<0?1:0)

using namespace std;

int sum, N, arr[MAX], counter = 0;
vector<int> v, ans[MAX];

void subsetSum(int start, int curSum) {
	if (curSum == sum) {
		ans[counter++] = v;
        return;
    }
	for (int i = start; i < N; i++) {
		curSum += arr[i];
		v.push_back(arr[i]);
		
		if (curSum <= sum)
			subsetSum(i+1, curSum);
		
		curSum -= arr[i];
		v.pop_back();
	}
}

int main() {
	int chk;
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (isNegative(arr[i])) {
			cout << "Invalid Input" << endl;
			exit(1);
		}
	}
	cin >> sum;
	counter = 0;
	subsetSum(0, 0);
	if (counter) {
		cout << "Subset Found: " << endl;
		for (int i = 0; i < counter; i++) {
			for (vector<int>::iterator p = ans[i].begin(); p != ans[i].end(); p++)
				cout << *p << " ";
			cout << endl;
		}
	}
	else
		cout << "Subset Not Found" << endl;

	return 0;
}
