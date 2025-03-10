#include<iostream>
#include<unordered_map>

using namespace std;

void printEvenfreElem(int arr[] , int n){
    unordered_map<int,int> freq;

    for(int i = 0 ; i<n ; i++){
        freq[arr[i]]++;
    }
    for(auto it : freq){
        if(it.second % 2 == 0){
            cout << it.first<< endl;
        }
    }
}
int main(){
    int N ;
    cin >>N;
    if(N < 0){
        cout << "invalid" << endl;
        return 0;
    }
    int arr[N];
    for(int i = 0 ; i < N ; i++){
        cin >> arr[i];

        if(arr[i] <= 0){
            cout << "invalid " << endl;
            return 0;
        }
    }
    printEvenfreElem(arr, N );
    return 0;

}