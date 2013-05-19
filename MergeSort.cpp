#include <iostream>
#include <stdlib.h>
#define MAX 1000000

using namespace std;

template <class T> 
class MergeSort {
	protected:
		T a[MAX];
		int size;
		void simple_merge(int low, int mid, int high);
		void merge_sort(int low, int high);
	public:
		void display();
		void input();
		void rand_input();
		void SortArray() {
			merge_sort(0, size-1);
		}
};

template <class T>
void MergeSort<T>::display() {
	cout << "The Elements In Sorted Order Are: ";
	for (int i = 0; i < size; i++) {
		cout << a[i] << "   ";
	}
	cout << endl;
}

template <class T>
void MergeSort<T>::simple_merge(int low, int mid, int high) {
	T c[MAX];
	int i, j, k, p, q;

	for (i = low, j = mid+1, k = 0; i <= mid && j <= high; ) {
		if (a[i] < a[j])
			c[k++] = a[i++];
		else
			c[k++] = a[j++];
	}
	
	while (i <= mid)
		c[k++] = a[i++];

	while (j <= high)
		c[k++] = a[j++];

	for (p = 0, q = low; p < k; p++, q++)
		a[q] = c[p];
}

template <class T>
void MergeSort<T>::merge_sort(int low, int high) {
	int mid = (low+high)/2;
	
	if (low < high) {
		merge_sort(low, mid);
		merge_sort(mid+1, high);
		simple_merge(low, mid, high);
	}
}

template <class T>
void MergeSort<T>::input() {
	cout << "Enter The Number Of Elements: ";
	cin >> size;
	
	cout << "Enter The Elements:\n";
	for (int i = 0; i < size; i++)
		cin >> a[i];
}

template <class T>
void MergeSort<T>::rand_input() {
	cout << "Enter The Number Of Elements: ";
	cin >> size;
	
	for (int i = 0; i < size; i++)
		a[i] = random()%100000;
}

int main() {
	clock_t b, e;
	b = clock();
	
	MergeSort<int> int_obj;

	int_obj.rand_input();
	int_obj.SortArray();
	int_obj.display();
	
	e = clock();
	
	cout << ((double)(e-b))/CLOCKS_PER_SEC << endl;
	return 0;
}
