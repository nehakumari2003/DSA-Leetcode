#include <iostream>
using namespace std;
int getsum(int *arr , int size){
    if(size == 0){
        return 0;
    }
    if(size==1){
        return arr[0];
    }
    int remaingPart = getsum(arr+1 ,size-1);
    int sum = arr[0] + remaingPart;
    return sum;
}
int main(){
    int arr[5] = {2, 4, 6, 5, 9};
    int size = 5;
    int sum = getsum(arr, 5);
    cout << "Sum is "<< sum << endl;
    return 0;
}