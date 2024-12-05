#include <iostream>
#include <vector>
#include <string>

using namespace std;

void reverseWords(const string str) {
    string result = "";
    vector<string> arr; // To store individual words

    // Split the string into words and store in the vector
    string word = "";
    for (char ch : str) {
        if (ch == ' ') {
            if (!word.empty()) {
                arr.push_back(word); // Add the word to the array
                word = "";
            }
        } else {
            word += ch; // Accumulate characters for the word
        }
    }
    if (!word.empty()) {
        arr.push_back(word); // Add the last word to the array
    }

    // Reverse the words and form the result
    for (int i = arr.size() - 1; i >= 0; --i) {
        result += arr[i];
        if (i > 0) {
            result += " "; // Add space between words
        }
    }

    // Print the final reversed sentence
    cout << result << endl;
}

int main() {
    string str = "welcome to code";
    reverseWords(str);
    return 0;
}
