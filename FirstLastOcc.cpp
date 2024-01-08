/*You have been given a sorted array/list 'arr' consisting of ‘n’ elements. You are also given an integer ‘k’.
Now, your task is to find the first and last occurrence of ‘k’ in 'arr'.
Note :
1. If ‘k’ is not present in the array, then the first and the last occurrence will be -1. 
2. 'arr' may contain duplicate elements.*/
#include<iostream>
using namespace std;
int firstOcc(int arr[], int n , int key){
    int s = 0, e = n-1;
    int mid = s+(e-s)/2;
    int ans = -1;
    while(s<e){
        if(arr[mid]==key){
            ans = mid;
            e=mid-1;
        }
        else if(key > arr[mid]){
            s = mid+1;
        }
        else if(key < arr[mid]){
            e = mid-1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
}
int LastOcc(int arr[], int n , int key){
    int s = 0, e = n-1;
    int mid = s+(e-s)/2;
    int ans = -1;
    while(s<e){
        if(arr[mid]==key){
            ans = mid;
            s=mid+1;
        }
        else if(key > arr[mid]){
            s = mid+1;
        }
        else if(key < arr[mid]){
            e = mid-1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
}
int main(){
    int even[5] = {1,2,3,3,5};
    int firstIndex = firstOcc(even, 5, 3);
    int lastIndex = LastOcc(even, 5, 3);
    
    if (firstIndex != -1) {
        cout << "First Occurrence of 3 is at index " << firstIndex << endl;
        cout << "Last Occurrence of 3 is at index " << lastIndex << endl;
        
    } else {
        cout << "Element 3 not found in the array." << endl;
    }

    return 0;
}
