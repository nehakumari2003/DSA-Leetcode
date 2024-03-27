#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int opened = 0;
        for(char c : s) {
            if(c == '(' && opened++ > 0) 
                res += c;
            if(c == ')' && opened-- > 1) 
                res += c;
        }
        return res;
    }
};

int main() {
    // Example usage:
    string input = "((()()))";
    Solution sol;
    string result = sol.removeOuterParentheses(input);
    cout << "Input: " << input << endl;
    cout << "Output: " << result << endl;
    return 0;
}
