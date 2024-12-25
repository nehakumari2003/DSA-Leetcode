#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int n, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n &&  arr[left] > arr[largest]){
        largest = left;
    }
    if(right < n &&  arr[right] > arr[largest]){
        largest = right;
    }
    if(largest != i){
        swap(arr[i] , arr[largest]);
        heapify(arr,n,largest);
    }
    
}

void buildmaxHeap(vector<int> &arr){
    int n = arr.size();
    for(int i = n/2 -1; i >= 0; i--){
        heapify(arr,n,i);
    }
}
void heapsort(vector<int> &arr){
    int n = arr.size();
    buildmaxHeap(arr);
    for(int i = n-1; i>0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}
int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    
    cout << "Original array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    heapsort(arr);

    cout << "Sorted array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}