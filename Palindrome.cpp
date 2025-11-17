#include <iostream>
using namespace std;
int main() {
    string s;
    cin>>s;
    int i = 0;
    int j = s.length()-1;
    while(i<j){
        if(s[i]==s[j]){
            i++;
            j--;
        }else{
            cout<<"not a palindrome";
            return 0;
        }
    }
    cout<<"palindrome";
    return 0;
}