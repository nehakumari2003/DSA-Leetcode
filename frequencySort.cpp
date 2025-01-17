#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        
        vector<pair<int, char>> freqVec;
        for (auto it : freq) {
            freqVec.push_back({it.second, it.first}); 
        }

       
        sort(freqVec.begin(), freqVec.end(), greater<pair<int, char>>());

        
        string result = "";
        for (auto it : freqVec) {
            result += string(it.first, it.second); 
        }

        return result; 
    }
};

int main() {
    Solution solution;
    string s = "tree";
    cout << "Sorted by frequency: " << solution.frequencySort(s) << endl;
    return 0;
}
