/* Given an integer array nums, find the 
subarray
 with the largest sum, and return its sum. */

#include<iostream>
#include<vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currentSum = 0;

        for(int i = 0 ; i < nums.size(); i++){
            currentSum = currentSum + nums[i];

            if(currentSum > maxSum){
                maxSum = currentSum;
            }
            if(currentSum < 0){
                currentSum = 0;
            }


        }

        return maxSum;
        
    }
};
int main() {
    
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    Solution solution;
    int result = solution.maxSubArray(nums);

    cout << "Maximum Subarray Sum: " << result << endl;

    return 0;
}