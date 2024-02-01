#include <iostream>
using namespace std;

bool linearSearch(int arr[], int size , int k){
    //base case
    if(size == 0){
        return false;
    }
    if(arr[0] == k){
        return true;
    }
    else{
        bool remaingPart = linearSearch(arr+1 , size-1, k);
        return remaingPart;
    }
}
int main(){
    int arr[5] = {3, 2, 1, 5, 6};
    int size = 5;
    int key = 6;
    bool ans = linearSearch(arr, size , key);
    if(ans){
        cout << "Present" << endl;
    }
    else{
        cout << "Absent" << endl;
    }
    return 0;
}