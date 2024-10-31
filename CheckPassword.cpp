#include <iostream>
#include <cstring>
using namespace std;

int CheckPassword(char str[], int n)
{
    if (n < 4)
    {
        return 0;
    }
    bool hasDigit = false;
    bool hasUppercase = false;

    if (str[0] >= '0' && str[0] <= '9')
    {
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            hasDigit = true;
        }
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            hasUppercase = true;
        }
        if (str[i] == ' ' || str[i] == '/')
        {
            return 0;
        }
    }
    if (hasDigit && hasUppercase)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{

    char str1[] = "aA1_67";
    char str2[] = "a987 abC012";

    cout << CheckPassword(str1, strlen(str1)) << endl;
    cout << CheckPassword(str2, strlen(str2)) << endl;

    return 0;
}