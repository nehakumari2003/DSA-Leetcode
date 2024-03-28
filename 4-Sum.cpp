/*Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order*/
#include <bits/stdc++.h>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin() , nums.end());
        for(int i = 0 ; i< n ; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1 ; j<n ; j++ ){
                if(j > i+1 && nums[j] == nums[j-1]) continue;

                int k = j+1;
                int l = n-1;
                while(k<l){
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if(sum == target){
                        vector<int> temp = {nums[i] , nums[j] , nums[k] , nums[l]};
                        ans.push_back(temp);
                        k++ ; l--;

                        while(k<l && nums[k] == nums[k-1]) k++;
                        while(k<l && nums[l] == nums[l+1]) l--;
                    }
                    else if(sum < target) k++;
                    else l--;
                }
            }
        }
        return ans;
    }
};

int main() {
    
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    Solution solution;
    vector<vector<int>> result = solution.fourSum(nums, target);

    
    for (const auto &quadruplet : result) {
        for (int num : quadruplet) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
