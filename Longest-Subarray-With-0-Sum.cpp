/*Problem statement
Ninja is given an array ‘Arr’ of size ‘N’. You have to help him find the longest subarray of ‘Arr’, whose sum is 0. You must return the length of the longest subarray whose sum is 0.



For Example:
For N = 5, and Arr = {1, -1, 0, 0, 1}, 
We have the following subarrays with zero sums: 
{{1, -1}, {1, -1, 0}, {1, -1, 0, 0}, {-1, 0, 0, 1}, {0}, {0, 0}, {0}}
Among these subarrays, {1, -1, 0, 0} and {-1, 0, 0, 1} are the longest subarrays with their sum equal to zero. Hence the answer is 4.*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int getLongestZeroSumSubarrayLength(vector<int> &arr){
    unordered_map<int,int> mpp;
    int maxi = 0;
    int sum = 0;
    int n = arr.size();
    for(int i = 0 ; i<n ; i++){
        sum += arr[i];
        if(sum == 0){
            maxi = i+1;
        }
        else{
            if(mpp.find(sum) != mpp.end()){
                maxi = max(maxi , i - mpp[sum]);
            }
            else{
                mpp[sum] = i;
            }
        }
    }
    return maxi;
}

int main() {
    vector<int> arr = {1, -2, 3, 4, -1, 4, -2, -2};
    cout << "Length of longest subarray with zero sum: " << getLongestZeroSumSubarrayLength(arr) << endl;
    return 0;
}
