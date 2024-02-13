/*Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.*/

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        return nums[n/2];

        
    }
};
int main(){
    Solution sol;
    vector<int> nums = {1, 2, 1, 2, 1, 1,1};
    int maj = sol.majorityElement(nums);
    cout << "Majority Element " << maj << endl;
    return 0;
}

