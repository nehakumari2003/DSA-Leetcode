class Solution {
public:
    int countSubstr(string& s, int k) {
        return atMostK(s, k) - atMostK(s, k - 1);
    }

private:
    int atMostK(string& s, int k) {
        if (k <= 0) return 0;

        int start = 0, result = 0;
        unordered_map<char, int> freq;

        for (int end = 0; end < s.size(); end++) {
            freq[s[end]]++;
            while (freq.size() > k) {
                freq[s[start]]--;
                if (freq[s[start]] == 0) {
                    freq.erase(s[start]);
                }
                start++;
            }

            
            result += (end - start + 1);
        }

        return result;
    }
};
