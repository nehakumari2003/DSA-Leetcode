#include <iostream>
using namespace std;

string reverseString(string s) {
    string rev_str = "";
    for(int i = 0; i < s.length(); i++) {
        rev_str = s[i] + rev_str;
    }
    return rev_str;
}

int main() {
    string str;

    cout << "Enter a string to reverse: ";
    getline(cin, str);

    string reversed = reverseString(str);
    cout << "Reversed string: " << reversed << endl;

    return 0;
}
