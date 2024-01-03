/*Longest Substring Without Repeating Characters*/

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int left = 0, right = 0;
        std::unordered_set<char> seen;
        int max = 0;
        while (right < s.length()) {
            char c = s[right];
            if (seen.insert(c).second) {
                max = std::max(max, right - left + 1);
                right++;
            } else {
                while (s[left] != c) {
                    seen.erase(s[left]);
                    left++;
                }
                seen.erase(c);
                left++;
            }
        }
        return max;
    }
};
