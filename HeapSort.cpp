#include <iostream>
#include <algorithm>
#include <cstring>
#include <sys/time.h>

#define MAX 1000000

using namespace std;

int N, arr[MAX];

void input() {
	cin >> N;
	for (int i = 0; i < N; i++)
		arr[i] = random()%100000;
}

void display() {
	for (int i = 0; i < N; i++)
		cout << arr[i] << "  ";
	cout << endl;
}

void heapify(int max, int start) {
	int i = start;
	while (2*i+1 < max && (arr[i] < arr[(2*i)+1] || arr[i] < arr[(2*i)+2])) {
		if ((arr[(2*i)+2] >= arr[(2*i)+1])) {
			if (2*i+2 < max) {
				swap(arr[i], arr[(2*i)+2]);
				i = (2*i)+2;
			
			}
			else {
				swap(arr[i], arr[(2*i)+1]);
				i = (2*i)+1;
			}
		}
		else {
			swap(arr[i], arr[(2*i)+1]);
			i = (2*i)+1;
		}
	}
}
int main() {
	struct timeval b, e;
	int j;
	
	input();
	
	gettimeofday(&b, NULL);
	for (int p = (N/2)-1; p >= 0; p--)
		heapify(N, p);
	j = N-1;
	while (j >= 0) {
		swap(arr[0], arr[j]);
		heapify(j, 0);
		j--;	
	}
	gettimeofday(&e, NULL);
	//display();
	cout << "Time Taken = " << ((double)e.tv_usec) - ((double)b.tv_usec) << endl;
	
	return 0;
}
