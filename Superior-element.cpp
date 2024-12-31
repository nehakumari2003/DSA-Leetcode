#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }

    int count = 0;
    int superior = INT_MIN;
    for(int i = n-1; i >= 0 ; i--){
        if(arr[i] > superior){
            count++;
            superior = arr[i];
        }
    }
    cout<< count << endl;

}