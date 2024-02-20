#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) { 
       sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i += 2) {
            if(nums[i] != nums[i - 1])
                return nums[i - 1];
        }
        return nums[nums.size() - 1];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 1, 2, 1, 2};
    cout << "Single number: " << sol.singleNumber(nums) << endl;
    return 0;
}
