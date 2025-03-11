#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int N;
    cin>>N;
    
    int bit_length = log2(N)+1;
    int mask = (1 << bit_length) -1;
    int tooglenumber = N^mask;
    cout<<tooglenumber<<endl;
     
    return 0;
}