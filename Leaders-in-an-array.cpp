#include <vector>
#include <climits> // For INT_MIN
#include <algorithm> 

using namespace std;

vector<int> superiorElements(vector<int>& a) {
    vector<int> ans;
    int maxi = INT_MIN;
    int n = a.size();

    for(int i = n - 1; i >= 0; i--) {
        if(a[i] > maxi) {
            ans.push_back(a[i]);
        }
        maxi = max(maxi, a[i]);
    }

    sort(ans.begin(), ans.end());
    return ans;
}


#include <iostream>

int main() {
    vector<int> arr = {10, 4, 6, 12, 8, 15, 20, 3};
    vector<int> result = superiorElements(arr);

    cout << "Superior elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
