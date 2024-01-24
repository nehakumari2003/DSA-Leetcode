/*You are given a three integers 'X', 'N', and 'M'. Your task is to find ('X' ^ 'N') % 'M'. A ^ B is defined as A raised to power B and A % C is the remainder when A is divided by C.*/

#include <iostream>
using namespace std;

int modularExponentiation(int x, int n, int m) {
    int res = 1;
    while (n > 0) {
        if (n & 1) {
            res = (1LL * (res) * (x) % m) % m;
        }
        x = (1LL * (x) * (x) % m) % m;
        n = n >> 1;
    }
    return res;
}
int main(){
    int base , exponent , modulus ;
    cout << "enter base : "<< endl;
    cin>> base;
    cout << "enter exponent  : "<< endl;
    cin>> exponent ;
    cout << "enter modulus  : "<< endl;
    cin>> modulus ;

    int result = modularExponentiation(base , exponent, modulus);

    cout <<"Result " << result <<endl;

    return 0;


}