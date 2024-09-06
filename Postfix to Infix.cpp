#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string postToInfix(string exp) {
        stack<string> st;
        int length = exp.length();
        

        for (int i = 0; i < length; i++) {
            char ch = exp[i];
            

            if (isalnum(ch)) {
                st.push(string(1, ch));
            }

            else {

                string operand2 = st.top(); st.pop();
                string operand1 = st.top(); st.pop();
                

                string infix = "(" + operand1 + ch + operand2 + ")";
                st.push(infix);
            }
        }
        
       
        return st.top();
    }
};


int main() {
    Solution sol;
    string postfix = "ABC/-AK/L-*";
    cout << sol.postToInfix(postfix) << endl;  // Output: "((A-(B/C))*((A/K)-L))"
    return 0;
}
