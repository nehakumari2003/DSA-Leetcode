#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr , int n , int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[smallest] > arr[left]) {
        smallest = left;
    }
    if (right < n && arr[smallest] > arr[right]) {
        smallest = right;
    }
    if (smallest != i) {
        swap(arr[smallest], arr[i]);
        heapify(arr, n, smallest);
    }
}

vector<int> buildMinHeap(vector<int> &arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    return arr;
}

int main() {
    vector<int> arr = {4, 10, 3, 5, 1};
    arr = buildMinHeap(arr);
    for (int val : arr) {
        cout << val << " ";
    }
    return 0;
}
