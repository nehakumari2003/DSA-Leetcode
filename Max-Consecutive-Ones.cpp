#include <vector>
#include <algorithm>
#include <climits> // for INT_MIN

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ctn = 0;
        int ans = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 1) {
                ans = max(ans, ctn);
                ctn = 0;
            } else {
                ctn++;
            }
        }
        ans = max(ans, ctn);
        return ans;
    }
};


#include <iostream>

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    cout << "Max consecutive ones: " << sol.findMaxConsecutiveOnes(nums) << endl;
    return 0;
}
