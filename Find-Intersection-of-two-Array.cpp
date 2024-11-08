#include <iostream>
#include <vector>

using namespace std;

vector<int> findIntersection(vector<int> &arr1 , vector<int> &arr2){
    int i = 0 , j = 0;
    vector<int> ans;
    while( i < arr1.size() && j < arr2.size()){
        if(arr1[i] < arr2[j]){
            i++;
        }
        else if(arr1[i] > arr2[i]){
            j++;
        }
        else{
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    return ans;
}