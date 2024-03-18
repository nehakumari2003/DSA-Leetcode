/*Problem statement
You are given an array 'arr' of length 'n' containing integers within the range '1' to 'x'.
Your task is to count the frequency of all elements from 1 to n.
Note:
You do not need to print anything. Return a frequency array as an array in the function such that index 0 represents the frequency of 1, index 1 represents the frequency of 2, and so on.*/

#include <bits/stdc++.h>
using namespace std;
void frequency(int arr[],int n){
    unordered_map<int,int> map;

    for(int i= 0 ; i< n ; i++){
        map[arr[i]]++;
    }
    for(auto x : map){
        cout << x.first<<" " <<x.second<<endl;
    }
}
int main(){
    int arr[] = {10,5,10,15,10,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    frequency(arr , n);
    return 0;
}