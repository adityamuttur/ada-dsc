#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <sys/time.h>

#define MAX 1000000 

using namespace std;

template <class T>
class qSort {
	protected:
		T a[MAX];
		int N;
		int partition (int, int);
		void quickSort(int, int);
	public:
		int mySort() {
			quickSort(0, N-1);
		}
		void display();
		void input();
};

template <class T>
int qSort<T>::partition (int low, int high) {
	int small = low+1, big = high, pivot = low;

	while(1) {
		while (a[small] <= a[pivot] && small <= high)
			small++;
		while (a[big] > a[pivot])
			big--;
		if (small < big)
			swap(a[small], a[big]);
		else {
			swap(a[big], a[pivot]);
			return big;
		}
	}
}

template <class T>
void qSort<T>::quickSort(int low, int high) {
	int mid;
	if (low < high) {
		mid = partition(low, high);
		quickSort(low, mid);
		quickSort(mid+1, high);
	}
}

template <class T>
void qSort<T>::display() {
	for (int i = 0; i < N; i++) 
		cout << a[i] << " ";
	cout << endl;
}

template <class T>
void qSort<T>::input() {
	//cout << "Enter The Number Of Elements: ";
	cin >> N;
	srand(12);
	for (int i = 0; i < N; i++)
		a[i] = i;//rand();
		//a[i] = N-i;
}

int main() {
	qSort<long long> obj;
	struct timeval b, e;

	obj.input();
	
	//cout << "The Unsorted Array Is: ";
	//obj.display();
	
	gettimeofday(&b, NULL);
	obj.mySort();
	gettimeofday(&e, NULL);
	
	//cout << "The Sorted Array Is: ";
	//obj.display();
	cout << "Time Taken = " << ((double)e.tv_usec) - ((double)b.tv_usec) << endl;

	return 0;
}
