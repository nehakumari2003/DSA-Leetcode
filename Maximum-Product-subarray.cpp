/*Given an integer array nums, find a 
subarray
 that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer*/

#include<bits/stdc++.h>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pre = 1, suff = 1;
        int n = nums.size();
        int ans = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            if(pre == 0) pre = 1;
            if(suff == 0) suff = 1;

            pre = pre * nums[i];
            suff = suff * nums[n - i - 1];
            ans = max(ans, max(pre, suff));
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2, 3, -2, 4}; 
    int Result = sol.maxProduct(nums);
    cout<< "Maximum product of a subarray: " << Result << endl;

    return 0;
}