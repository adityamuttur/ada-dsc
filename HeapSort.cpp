#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 1000

int N, arr[MAX];

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) 
        cin >> arr[i];
}

void maxHeapify(int size, int start) {
    int l = 2*start+1, r = 2*start+2, largest;
    
    if (l <= size-1 && arr[l] > arr[start])
        largest = l;
    else
        largest = start;
    
    if (r <= size && arr[r] > arr[largest])
        largest = r;
    
    if (largest != start) {
        swap(arr[start], arr[largest]);
        maxHeapify(size, largest);
    }
}

void buildMaxHeap() {
    int size = N-1;
    for (int i = size/2; i >= 0; i--)
        maxHeapify(size, i);
}

int main() {
    int size;
    
    input();
    buildMaxHeap();
    
    size = N-1;
    for (int i = N-1; i >= 1; i--) {
        swap(arr[0], arr[size]);
        size--;
        maxHeapify(size, 0);
    }
    
    for (int i = 0; i < N; i++)
        cout << arr[i] << "  ";
    cout << endl;

    return 0;
}
