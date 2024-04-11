/*Problem statement
You have been given a sorted array/list 'arr' consisting of ‘n’ elements. You are also given an integer ‘k’.

Now, your task is to find the first and last occurrence of ‘k’ in 'arr'.
Note :
1. If ‘k’ is not present in the array, then the first and the last occurrence will be -1. 
2. 'arr' may contain duplicate elements. */
#include <bits/stdc++.h>
using namespace std;

int firstOcc(vector<int> &arr, int n, int k) {
    int low = 0, high = n - 1;
    int first = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == k) {
            first = mid;
            high = mid - 1;
        } else if (arr[mid] < k)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return first;
}

int lastOcc(vector<int> &arr, int n, int k) {
    int low = 0, high = n - 1;
    int last = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == k) {
            last = mid;
            low = mid + 1;
        } else if (arr[mid] < k)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return last;
}

pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k) {
    int first = firstOcc(arr, n, k);
    if (first == -1) return {-1, -1};
    int last = lastOcc(arr, n, k);
    return {first, last};
}
int main(){
    vector<int> arr = {1, 2, 2, 2, 3, 4, 5};
    int k = 2;
    int n = arr.size();
    pair<int , int> positions = firstAndLastPosition(arr , n , k);
    cout << "First Occurrence: " << positions.first << endl;
    cout << "Last Occurrence: " << positions.second << endl;
    return 0;
}