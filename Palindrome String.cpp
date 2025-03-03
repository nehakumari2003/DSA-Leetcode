#include<iostream>
using namespace std;

bool isPalindrome(string s){
    int l = 0 , r = s.length()-1;
    while(l < r){
        if(s[l] != s[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;

}

int main(){
    string str = "racecar";
    cout<< (isPalindrome(str) ? "Palindrome" : "Not Palindrome") << endl;
    return 0;
}