/*You are given an array 'arr' having 'n' distinct integers sorted in ascending order. The array is right rotated 'r' times
Find the minimum value of 'r'.
Right rotating an array means shifting the element at 'ith' index to (‘i+1') mod 'n' index, for all 'i' from 0 to ‘n-1'.*/

#include <bits/stdc++.h>
using namespace std;
int findKRotation(vector<int> &arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    int index = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        
        if (arr[low] <= arr[high]) {
            if (arr[low] < ans) {
                index = low;
                ans = arr[low];
            }
            break;
        }

        
        if (arr[low] <= arr[mid]) {
            
            if (arr[low] < ans) {
                index = low;
                ans = arr[low];
            }

            
            low = mid + 1;
        }
        else { 
            if (arr[mid] < ans) {
                index = mid;
                ans = arr[mid];
            }

            high = mid - 1;
        }
    }
    return index;
}
int main(){
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int Result = findKRotation(arr);
    cout << "The array is rotated " << Result << " times.\n";
    return 0;
}


