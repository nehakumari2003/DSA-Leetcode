#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n){
    int i, j;
    bool swapped;
    for(i = 0; i<n-1 ; i++ ){
        swapped = false;
        for(j = 0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if(swapped == false)
            break;
    }
}
void printArray(int arr[], int size){
    for(int i = 0; i<size; i++){
        cout<< " "<<arr[i]; 
    }
}


int main(){
    int arr[] = {10, 1, 7, 6, 14, 9};
    int N = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,N);
    cout<< "Sorted Array \n";
    printArray(arr, N);
    return 0;
}