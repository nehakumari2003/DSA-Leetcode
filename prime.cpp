#include<iostream>

using namespace std;

bool isprime(int n){
    if(n <= 1){
        return false;
    }
    for(int i = 2 ; i*i <= n ; i++){
        if( n % i == 0){
            return false;
        }
    }
    return true;
}
int primeSum(int n){
    int sum = 0;
    for(int i = 2 ; i < n; i++){
        if(isprime(i)){
            sum += i;
        }
    }   
    return sum;
}
int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Sum of all prime numbers less than " << n << " is: " << primeSum(n) << endl;

    return 0;
}