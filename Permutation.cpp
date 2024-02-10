/*Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void solve(vector<int>& nums, vector<vector<int>>& ans, int index) {
        if (index >= nums.size()) {
            ans.push_back(nums);
            return;
        }
        for (int j = index; j < nums.size(); j++) {
            swap(nums[index], nums[j]);
            solve(nums, ans, index + 1);
            // Backtrack
            swap(nums[index], nums[j]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index = 0;
        solve(nums, ans, index);
        return ans;
    }
};

int main() {
    
    Solution solution;
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> result = solution.permute(nums);

    // Displaying the result
    for (const auto& perm : result) {
        cout << "[ ";
        for (int num : perm) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
