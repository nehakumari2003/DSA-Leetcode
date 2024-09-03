#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string preToPost(string pre_exp) {
        stack<string> st;
        int length = pre_exp.length();
        

        for (int i = length - 1; i >= 0; i--) {
            char ch = pre_exp[i];

            if (isalnum(ch)) {
                st.push(string(1, ch));
            }

            else {

                string operand1 = st.top(); st.pop();
                string operand2 = st.top(); st.pop();
                

                string postfix = operand1 + operand2 + ch;
                st.push(postfix);
            }
        }
        

        return st.top();
    }
};

int main() {
    Solution sol;
    string prefix = "*-A/BC-/AKL";
    cout << sol.preToPost(prefix) << endl;  
    return 0;
}
