#include <iostream>
using namespace std;

int main()
{
    string str;
    cout << "Enter a string : " << endl;
    cin >> str;

    int start = 0;
    int end = str.length()-1;
    bool ispalindrome = false;
    while (start < end)
    {
        if(str[start] == str[end])
        {
            ispalindrome = true;
            break;
        }
        start++;
        end--;
    }

    if (ispalindrome)
    {
        cout << "String is Palindrome " << endl;
    }
    else
    {
        cout << "NOt a palindrome " << endl;
    }
    return 0;
}