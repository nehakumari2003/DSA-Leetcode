#include <deque>
#include <vector>
using namespace std;

vector<int> firstNegative(vector<int> arr, int n, int k) {
    deque<int> dq;  // Correctly declare deque
    vector<int> ans;  // Answer vector of type int
    
    // Process first window of size k
    for(int i = 0; i < k; i++) {
        if(arr[i] < 0) {
            dq.push_back(i);  // Push the index of negative numbers
        }
    }

    // Push the answer for the first window
    if(!dq.empty()) {
        ans.push_back(arr[dq.front()]);  // Add the first negative number
    } else {
        ans.push_back(0);  // No negative number in the first window
    }

    // Process the remaining windows
    for(int i = k; i < n; i++) {
        // Remove elements that are out of the current window
        if(!dq.empty() && (i - dq.front()) >= k) {
            dq.pop_front();
        }

        // Add current element if it is negative
        if(arr[i] < 0) {
            dq.push_back(i);
        }

        // Add the first negative number of the current window
        if(!dq.empty()) {
            ans.push_back(arr[dq.front()]);
        } else {
            ans.push_back(0);
        }
    }

    return ans;
}
