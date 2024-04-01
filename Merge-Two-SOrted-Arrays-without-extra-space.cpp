/*Problem statement
Given two non-decreasing sorted arrays, ‘A’ and ‘B’, having ‘N’ and ‘M’ elements, respectively.



You must merge these arrays, ‘A’ and ‘B’, into a sorted array without using extra space. Of all the 'N + M' sorted elements, array 'A' should contain the first 'N' elements, and array 'B' should have the last 'M' elements.

*/
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b) {
    int n = a.size();
    int m = b.size();
    int left = n - 1;
    int right = 0;

    while (left >= 0 && right < m) {
        if (a[left] > b[right]) {
            swap(a[left], b[right]);
            left--, right++;
        } else {
            break;
        }
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
}

int main() {
    
    vector<long long> a = {1, 3, 5, 7};
    vector<long long> b = {2, 4, 6, 8};
    
    mergeTwoSortedArraysWithoutExtraSpace(a, b);

    
    for (auto num : a) {
        cout << num << " ";
    }
    cout << endl;

    for (auto num : b) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
