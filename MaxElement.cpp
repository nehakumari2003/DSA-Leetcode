#include <iostream>
using namespace std;

int maxelement(int arr[] , int size){
    int max_ele = arr[0];
    for(int i = 1 ; i < size ; i++){
        if(arr[i] > max_ele){
            max_ele = arr[i];
        }
    }
    return max_ele;
}