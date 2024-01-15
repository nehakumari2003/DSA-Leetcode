/*A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.*/

#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    bool valid(char ch) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            return true;
        }
        return false;
    }

    char toLowerCase(char ch) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
            return ch;
        else {
            char temp = ch - 'A' + 'a';
            return temp;
        }
    }

    bool checkPalindrome(string a) {
        int s = 0;
        int e = a.length() - 1;

        while (s <= e) {
            if (a[s] != a[e]) {
                return false;
            } else {
                s++;
                e--;
            }
        }
        return true;
    }

public:
    bool isPalindrome(string s) {

        // Remove non-alphanumeric characters
        string temp = "";
        for (int j = 0; j < s.length(); j++) {
            if (valid(s[j])) {
                temp.push_back(s[j]);
            }
        }

        // Convert to lowercase
        for (int j = 0; j < temp.length(); j++) {
            temp[j] = toLowerCase(temp[j]);
        }

        // Check palindrome
        return checkPalindrome(temp);
    }
};

int main() {
    Solution sol;
    
    // Example usage
    string input = "A man, a plan, a canal: Panama";
    bool result = sol.isPalindrome(input);
    if (result) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }
    

    return 0;
}
