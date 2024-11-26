#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool areAnagrams(string str1, string str2) {

    if (str1.length() != str2.length()) {
        return false;
    }

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    return str1 == str2;
}

int main() {
    string str1 = "listen";
    string str2 = "silent";

    if (areAnagrams(str1, str2)) {
        cout << "Yes, they are anagrams." << endl;
    } else {
        cout << "No, they are not anagrams." << endl;
    }

    return 0;
}
