#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {

        unordered_map<char, char> mapST; // Maps characters from s to t
        unordered_map<char, char> mapTS; // Maps characters from t to s

        // Iterate through both strings
        for (int i = 0; i < s.length(); i++) {
            char c1 = s[i]; // Character from string s
            char c2 = t[i]; // Character from string t

            // Check if c1 is already mapped in mapST
            if (mapST.count(c1)) {
                // If it is mapped, check if the mapping is consistent
                if (mapST[c1] != c2) {
                    return false; // Inconsistent mapping, return false
                }
            } else {
                // If c1 is not mapped, add the mapping c1 -> c2
                mapST[c1] = c2;
            }

            // Check if c2 is already mapped in mapTS
            if (mapTS.count(c2)) {
                // If it is mapped, check if the mapping is consistent
                if (mapTS[c2] != c1) {
                    return false; // Inconsistent mapping, return false
                }
            } else {
                // If c2 is not mapped, add the mapping c2 -> c1
                mapTS[c2] = c1;
            }
        }


        return true;
    }
};

int main() {
    Solution solution;

    string s1 = "egg", t1 = "add";
    cout << "Are \"" << s1 << "\" and \"" << t1 << "\" isomorphic? " 
         << (solution.isIsomorphic(s1, t1) ? "Yes" : "No") << endl;

    string s2 = "foo", t2 = "bar";
    cout << "Are \"" << s2 << "\" and \"" << t2 << "\" isomorphic? " 
         << (solution.isIsomorphic(s2, t2) ? "Yes" : "No") << endl;

    string s3 = "paper", t3 = "title";
    cout << "Are \"" << s3 << "\" and \"" << t3 << "\" isomorphic? " 
         << (solution.isIsomorphic(s3, t3) ? "Yes" : "No") << endl;

    return 0;
}
