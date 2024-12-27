#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ; 
    cin >>n;

    int sum = (n*(n+1)/2);
    int ans = sum +1;
    cout<< (ans%100000007)<<endl;

    return 0;

}