#include <iostream>
#include <string>
using namespace std;

string replacechar(string str, char ch1, char ch2) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ch1) {
            str[i] = ch2;
        } else if (str[i] == ch2) {
            str[i] = ch1;
        }
    }
    return str;
}

int main() {
    string str = "apple";
    char ch1 = 'a';
    char ch2 = 'b';

    cout << "Original string: " << str << endl;
    cout << "Modified string: " << replacechar(str, ch1, ch2) << endl;

    return 0;
}
