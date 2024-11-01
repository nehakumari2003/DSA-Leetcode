#include<iostream>
using namespace std;
int main () {
    int n ;
    cin >> n;
    int sum = 0;
    while(n > 0){
        sum += n%2;
        n/=2;
    }
    cout<< "sum will be : " << sum <<endl;

    return 0;
}
