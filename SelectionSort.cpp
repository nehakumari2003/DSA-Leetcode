#include<iostream>
using namespace std;

void swap(int *a,int *b){
    int temp= *a;
    *a= *b;
    *b = temp;
}
void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<< " ";
    }
    cout<<endl;
}
void selectionSort(int arr[], int size){
    for(int i=0; i<size-1; i++){
        int min_ind=i;
        for(int j=i+1; j<size; j++){
            if(arr[j]<arr[min_ind]){
                min_ind=j;
            }

        }
        swap(&arr[min_ind],&arr[i]);
    }
}
int main(){
    int data[]={20,12,10,15,2};
    int size=sizeof(data)/sizeof(data[0]);
    selectionSort(data,size);
    cout<<"Sorted array in ascending order"<< endl;
    printArray(data,size);
}