class Solution {
public:
    string reverseWords(string s) {
        int left = 0;
        int right = s.length() - 1;

        // Trim leading spaces
        while (left <= right && s[left] == ' ') left++;

        // Trim trailing spaces
        while (right >= left && s[right] == ' ') right--;

        string temp = "";
        string ans = "";

        while (left <= right) {
            char ch = s[left];
            
            if (ch != ' ') {
                temp += ch;
            } else if (ch == ' ' && temp != "") {
                if (ans != "") ans = temp + " " + ans;
                else ans = temp;
                temp = "";

                // Skip consecutive spaces
                while (left <= right && s[left + 1] == ' ') left++;
            }
            
            left++;
        }
        
        // Add the last word if it exists
        if (temp != "") {
            if (ans != "") ans = temp + " " + ans;
            else ans = temp;
        }

        return ans;    
    }
};
