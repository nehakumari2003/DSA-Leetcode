/*Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 */

class Solution {
public:
    bool isPermutation(vector<int>& arr,vector<int>& brr){
        for(int i=0;i<26;i++)
            if(brr[i] != arr[i])
                return false;

        return true;
    }
    bool isContains(vector<int>& arr,vector<int>& brr){
        for(int i=0;i<26;i++)
            if(brr[i] < arr[i])
                return false;

        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        int i=0,j=0;
        vector<int> arr(26,0),brr(26,0);
        for(int i=0;i<s1.size();i++){
            arr[s1[i]-'a']++;
        }
        while(j<s2.size()){
            brr[s2[j++]-'a']++;
            if(isPermutation(arr,brr)) return true;
            while(isContains(arr,brr) and i<=j){
                brr[s2[i++]-'a']--;
                if(isPermutation(arr,brr)) return true;
            }
        }
        return false;
    }
};