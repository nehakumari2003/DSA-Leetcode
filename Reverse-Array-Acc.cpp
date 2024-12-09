#include<iostream>
#include<algorithm>

using namespace std;

int ans(int a[] , int n){
    reverse(a,a+n);
    int res = 0 ;

    for(int i = 0 ; i<n ; i+=2){
        res += a[i];
    }
    return res;
}
int main() {
    
    int n = 6;
    int a[] = {3, 1, 4, 1, 5, 9}; 


    int result = ans(a, n);
    cout << "Result: " << result << endl;

    return 0;
}