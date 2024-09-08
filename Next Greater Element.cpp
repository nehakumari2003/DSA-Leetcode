class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int> ans(n);
        stack<int> st;
        ans[n-1] = -1;
        st.push(nums2[n-1]);

        for(int i = n-2 ; i >= 0 ; i--){
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = -1;
            }
            else{
                ans[i] = st.top();
            }
            st.push(nums2[i]);
        }
        unordered_map<int , int> mp;
        for(int i = 0 ; i<n; i++){
            mp[nums2[i]] = ans[i];
        }
        vector<int> finalans(nums1.size());
        for(int i = 0 ; i<nums1.size() ; i++){
            finalans[i] = mp[nums1[i]];
        }
        return finalans;
    }
};