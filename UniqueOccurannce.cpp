/*Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // Step 1: Sort the input vector
        sort(arr.begin(), arr.end());

        // Step 2: Count occurrences and store in 'ans' vector
        vector<int> ans;
        int i = 0;
        while (i < arr.size()) {
            int count = 1;
            for (int j = i + 1; j < arr.size(); j++) {
                if (arr[i] == arr[j])
                    count++;
            }
            ans.push_back(count);
            i = i + count;
        }

        // Step 3: Sort the occurrences vector
        sort(ans.begin(), ans.end());

        // Step 4: Check for uniqueness
        for (int i = 0; i < ans.size() - 1; i++) {
            if (ans[i] == ans[i + 1])
                return false;
        }

        // All occurrences are unique
        return true;
    }
};

int main() {
    // Example usage
    Solution solution;
    vector<int> input = {4, 2, 1, 1, 3, 3, 2, 4, 4};
    
    if (solution.uniqueOccurrences(input)) {
        cout << "The occurrences are unique." << endl;
    } else {
        cout << "The occurrences are not unique." << endl;
    }

    return 0;
}
