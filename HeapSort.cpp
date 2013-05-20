#include <iostream>
#include <algorithm>

using namespace std;

#define SIZE 10000

int arr[SIZE];

void maxHeapify(int start, int N) {
    int i = start, child = 2*start;
    
    while (child <= N) {
        if (child < N)
            if (arr[child] < arr[child+1])
                child++;
        if (arr[i] <= arr[child]) {
            swap(arr[i], arr[child]);
            i = child;
            child = 2*i;
        }
        else
            break;
    }
}

void buildMaxHeap(int N) {
    for (int i = (N/2); i >= 1; i--)
        maxHeapify(i, N);
}

int main() {
    int N;
    
    cin >> N;
    
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    
    buildMaxHeap(N);
    
    for (int i = N; i >= 1; i--) {
        swap(arr[1], arr[i]);
        maxHeapify(1, i-1);
    }
    
    for (int i = 1; i <= N; i++)
        cout << arr[i] << " ";
    cout << endl;
    
    return 0;
}
