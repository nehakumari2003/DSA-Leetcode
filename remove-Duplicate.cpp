#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> removeDulicate(vector<int> &arr){
    if(arr.size() == 0){
        return arr;
    }
    sort(arr.begin() , arr.end());

    int index = 0;

    for(int i = 1 ; i < arr.size() ; i++){
        if(arr[i] != arr[index]){
            index++;
            arr[index] = arr[i];
        }
    }
    arr.resize(index+1);
    return arr;
}