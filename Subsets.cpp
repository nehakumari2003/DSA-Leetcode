/*Given an integer array nums of unique elements, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.*/
#include <iostream>
#include <vector>

using namespace std; 

class Solution {
private:
    void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans) {
        // Base case
        if (index >= nums.size()) {
            ans.push_back(output);
            return;
        }

        // Exclude
        solve(nums, output, index + 1, ans);

        // Include
        int element = nums[index];
        output.push_back(element);
        solve(nums, output, index + 1, ans);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        solve(nums, output, index, ans);
        return ans;    
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,2,3};
    vector<vector<int>> Result = sol.subsets(nums);
    cout << "Subsets: \n";
    for (const auto& subset : Result) {
        cout << "[";
        for (const auto& element : subset) {
            cout << element << " ";
        }
        cout << "]\n";
    }

    return 0;
}
/*
output[]
[1 ]
[2 ]
[1 2 ]
[3 ]
[1 3 ]
[2 3 ]
[1 2 3 ]*/