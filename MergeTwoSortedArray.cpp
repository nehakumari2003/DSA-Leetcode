#include <iostream>
#include <vector>

using namespace std;

vector<int> mergeTwoSortedArray(vector<int> arr1 , vector<int> arr2){
    vector<int> merge;
    int i = 0 , j = 0;
    while(i < arr1.size() && j < arr2.size()){
        if(arr1[i] < arr2[j]){
            merge.push_back(arr1[i]);
            i++;
        }
        else{
            merge.push_back(arr2[j]);
            j++;
        }
    }
    while(i < arr1.size()){
        merge.push_back(arr1[i]);
        i++;
    }
    while(j < arr2.size()){
        merge.push_back(arr2[j]);
        j++;
    }
    return merge;
}