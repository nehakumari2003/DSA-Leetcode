#include <iostream>
using namespace std;

int sumOfDigit(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;  
        n /= 10;        
    }
    return sum;
}

bool isPrime(int num) {
    if (num <= 1) {
        return false; 
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false; 
        }
    }
    return true; 
}

bool isGooglyPrime(int n) {
    int digitSum = sumOfDigit(n);  
    return isPrime(digitSum);     
}

int main() {
    int N;
    cout << "Enter a number: ";
    cin >> N;
    
    if (isGooglyPrime(N)) {
        cout << "Yes, it is a googly prime number." << endl;
    } else {
        cout << "No, it is not a googly prime number." << endl;
    }

    return 0;
}
