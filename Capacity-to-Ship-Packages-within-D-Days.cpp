
#include <bits/stdc++.h>
#include <vector>
#include <algorithm> // For max_element
#include <numeric>   // For accumulate

using namespace std;

class Solution {
public:
    int findDays(vector<int> &weights, int cap) {
        int d = 1, load = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (weights[i] + load > cap) {
                d += 1;
                load = weights[i];
            } else {
                load += weights[i];
            }
        }
        return d;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while (low <= high) {
            int mid = (low + high) / 2;
            int numberOfDays = findDays(weights, mid);
            if (numberOfDays <= days) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main() {
    Solution solution;

    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;

    int minCapacity = solution.shipWithinDays(weights, days);
    cout << "Minimum capacity required to ship within " << days << " days: " << minCapacity << endl;

    return 0;
}
