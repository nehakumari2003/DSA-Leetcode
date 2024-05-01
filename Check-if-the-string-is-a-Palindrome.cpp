/*Problem statement
You are given a string 'S'. Your task is to check whether the string is palindrome or not. For checking palindrome, consider alphabets and numbers only and ignore the symbols and whitespaces.

Note :

String 'S' is NOT case sensitive.*/

#include <iostream>
#include <cctype>

using namespace std;

bool isAlphanumeric(char c) {
    return isalnum(c); 
}

bool checkPalindrome(const string& s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        while (left < right && !isAlphanumeric(s[left])) { 
            left++;
        }
        while (left < right && !isAlphanumeric(s[right])) { 
            right--;
        }
        if (left < right && tolower(s[left]) != tolower(s[right])) { 
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    string input;
    cout << "Enter the string: ";
    getline(cin, input); 
    if (checkPalindrome(input)) {
        cout << "Palindrome\n";
    } else {
        cout << "Not Palindrome\n";
    }

    return 0;
}
