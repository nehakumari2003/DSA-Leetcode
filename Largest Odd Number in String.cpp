class Solution {
public:
    string largestOddNumber(string num) {
        if((num.back() - '0') % 2 == 1) return num;

        for(int i = num.length() -1; i >= 0; i--){
            int j = num[i] - '0'; // Correct conversion from char to int
            if(j % 2 == 1) {
                return num.substr(0, i+1);
            }
        }
        return "";
    }
};