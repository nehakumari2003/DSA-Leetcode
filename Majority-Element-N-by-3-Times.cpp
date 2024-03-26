/*Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0 , cnt2 = 0;
		int ele1 = INT_MIN;
		int ele2 = INT_MIN;
		for(int i = 0 ;i < nums.size() ; i++){
			if(cnt1==0 && ele2 != nums[i]){
				cnt1 = 1;
				ele1 = nums[i];
			}
			else if(cnt2 == 0 && ele1 != nums[i]){
				cnt2=1;
				ele2 = nums[i];
			}
			else if(nums[i] == ele1) cnt1++;
			else if(nums[i] == ele2) cnt2++;

			else{
				cnt1 -- , cnt2 -- ;
			}
		}
		vector<int> ls;
		cnt1 =0 , cnt2 = 0 ;
		for(int i =0 ; i<nums.size() ; i++){
			if(ele1 == nums[i]) cnt1++;
			if(ele2 == nums[i]) cnt2 ++;
		}	
		int mini = (int)((nums.size()/3) + 1);
		if(cnt1 >= mini) ls.push_back(ele1);
		if(cnt2 >= mini) ls.push_back(ele2);
		sort(ls.begin() , ls.end());
		return ls;

    }
};
int main(){
    int n;
    cout<<"Enter the size of an  array : "<<endl;
    cin >> n;
    
    vector<int> nums(n);
    cout<<"Enter the elements of an array : " << endl;
    for(int i = 0 ; i<n ; i++){
        cin>>nums[i];
    }
    Solution solution;
    vector<int> Result = solution.majorityElement(nums);

    cout << "Elements appearing more than ⌊n/3⌋ times: ";
    for(int i = 0 ; i<Result.size() ; i++){
        cout<< Result[i] << " ";
    }
    cout << endl;

    return 0;
}