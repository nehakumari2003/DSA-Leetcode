/*Problem statement
Given an array ‘A’ consisting of ‘N’ integers and an integer ‘B’, find the number of subarrays of array ‘A’ whose bitwise XOR( ⊕ ) of all elements is equal to ‘B’.
A subarray of an array is obtained by removing some(zero or more) elements from the front and back of the array.*/
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int subarraysWithSumK(vector<int> a, int b)
{
    int xr = 0;
    map<int, int> mpp;
    mpp[xr]++;
    int cnt = 0;
    for (int i = 0; i < a.size(); i++)
    {
        xr = xr ^ a[i];
        int x = xr ^ b;
        cnt += mpp[x];
        mpp[xr]++;
    }
    return cnt;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int target = 5;
    cout << "Number of subarrays with sum equal to " << target << ": " << subarraysWithSumK(arr, target) << endl;
    return 0;
}
