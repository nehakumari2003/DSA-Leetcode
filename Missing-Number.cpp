/*Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.*/

#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0;
        for(int j = 0; j < n; j++) {
            if(nums[j] != i) {
                return i;
            }
            i++;
        }
        return n;
    }
};
#include <iostream>

int main() {
    Solution sol;
    vector<int> nums = {3, 0, 1};
    cout << "Missing number: " << sol.missingNumber(nums) << endl;
    return 0;
}
