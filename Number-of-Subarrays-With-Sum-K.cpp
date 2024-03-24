/*Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       unordered_map<int,int> mpp;
       mpp[0] = 1;

       int preSum = 0 , cnt = 0;
       for(int i = 0 ; i <nums.size() ; i++){
            preSum += nums[i];
            int remove = preSum-k;
            cnt += mpp[remove];
            mpp[preSum] += 1;
        } 
        
        return cnt;
    }
};

int main() {
    
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 7;
    int result = sol.subarraySum(nums, k);
    cout << "Number of subarrays with sum " << k << ": " << result << endl;

    return 0;
}
