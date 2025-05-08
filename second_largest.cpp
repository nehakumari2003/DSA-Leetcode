#include <iostream>
#include<climits>
using namespace std;

int main(){
    int n;
    cout<<"Enter a number of elements " <<endl;
    cin>>n;
    int arr[100];
    for(int i = 0 ; i < n ; i++){       
        cin>>arr[i];
    }

    int lar = INT_MIN;
    int seclag = INT_MIN;

    for(int i = 0 ; i < n ; i++){
        if(arr[i] > lar){
            seclag = lar;
            lar = arr[i];
        }
        else if(arr[i] > seclag && arr[i] < lar){
            seclag = arr[i];
        }
    }
    if(seclag == INT_MIN){
        return -1;
    }
    else{
        cout<< "SECLAGEST is : " << seclag <<endl;
    }
    return 0;
}