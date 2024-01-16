/*You have been given a string 'STR' of words. You need to replace all the spaces between words with “@40”.*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        while (s.length() != 0 && s.find(part) < s.length()) {
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};

int main() {
    Solution solution;

    string inputString, substringToRemove;

    // Input the original string
    cout << "Enter the original string: ";
    getline(cin, inputString);

    // Input the substring to remove
    cout << "Enter the substring to remove: ";
    getline(cin, substringToRemove);

    // Call the removeOccurrences function
    string result = solution.removeOccurrences(inputString, substringToRemove);

    // Output the result
    cout << "String after removing occurrences: " << result << endl;

    return 0;
}
