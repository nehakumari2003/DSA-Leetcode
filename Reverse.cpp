#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int st = 0;
        int e = s.size()-1;
        while(st < e){
            swap(s[st++] , s[e--]);
        }
        
    }
};

int main(){

    Solution solution;
    vector<char> myString = {'N', 'e', 'h', 'a'};
    solution.reverseString(myString);
    for (char c : myString) {
        cout << c << " ";
    }
    
    return 0;
}
