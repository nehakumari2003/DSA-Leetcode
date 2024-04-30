/*Given an array of strings words, return the first palindromic string in the array. If there is no such string, return an empty string "".

A string is palindromic if it reads the same forward and backward.*/

#include<iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private :
    bool isPalindrome(const string &word) {
        int left = 0, right = word.length() - 1;
        while (left < right) {
            if (word[left] != word[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
public:
    string firstPalindrome(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            if (isPalindrome(words[i])) {
                return words[i];
            }
        }
        return "";
    }
};

int main() {
    Solution solution;
    vector<string> words = {"apple", "banana", "radar", "car", "level"};
    string palindrome = solution.firstPalindrome(words);
    if (palindrome != "") {
        cout << "First palindrome word: " << palindrome << endl;
    } else {
        cout << "No palindrome word found." << endl;
    }
    return 0;
}
