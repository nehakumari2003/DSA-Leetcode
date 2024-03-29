/*You are given a string 'STR' containing lowercase English letters from a to z inclusive. Your task is to find all non-empty possible subsequences of 'STR'.

A Subsequence of a string is the one which is generated by deleting 0 or more letters from the string and keeping the rest of the letters in the same order.*/

#include <iostream>
#include <vector>
using namespace std;

void solve(vector<string>& ans, string str, string output, int i) {
    // Base case
    if (i >= str.length()) {
        if (output.length() > 0) {
            ans.push_back(output);
        }
        return;
    }

    // Exclude
    solve(ans, str, output, i + 1);

    // Include
    output.push_back(str[i]);
    solve(ans, str, output, i + 1);
}

vector<string> subsequences(string str) {
    vector<string> ans;
    string output = "";
    solve(ans, str, output, 0);
    return ans;
}

int main() {
    string inputStr = "abc";
    vector<string> result = subsequences(inputStr);

    
    cout << "Subsequences: \n";
    for (const auto& subsequence : result) {
        cout << "[" << subsequence << "]\n";
    }

    return 0;
}
                   