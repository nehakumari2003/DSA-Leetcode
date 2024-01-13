/*Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // Create a temporary vector to store rotated elements
        vector<int> temp(nums.size());

        // Perform rotation
        for(int i = 0; i < nums.size(); i++) {
            temp[(i + k) % nums.size()] = nums[i];
        }

        // Update the original vector with rotated elements
        nums = temp;
    }
};

int main() {
    // Example usage
    Solution solution;

    // Input vector
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};

    // Number of positions to rotate
    int k = 3;

    // Rotate the vector
    solution.rotate(nums, k);

    // Display the rotated vector
    cout << "Rotated vector: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout <<endl;

    return 0;
}
