/*Problem statement
You are given an integer 'n'.
Return 'true' if 'n' is an Armstrong number, and 'false' otherwise.
Note:
An Armstrong number is a number (with 'k' digits) such that the sum of its digits raised to 'kth' power is equal to the number itself. For example, 371 is an Armstrong number because 3^3 + 7^3 + 1^3 = 371.*/

#include<iostream>
#include<cmath>
using namespace std;

bool isArmstrong(int num){
    int sum = 0;
    int originalNum = num;
    int numDigits = log10(num)+1;
  
    while(num!=0){
        int digit = num%10;
        sum += pow(digit , numDigits);
        num = num/10;
    }
    return sum == originalNum;

}
int main(){
    int num;
    cout << "enter a number : ";
    cin >> num;

    if(isArmstrong(num)){
        cout << num << " is an Armstrong number "<<endl;
    }
    else{
        cout<< num << " is not Armstrong number " <<endl;
    }

    return 0;
}