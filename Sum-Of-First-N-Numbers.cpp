/*Problem statement
You are given an integer ‘n’.
Your task is determining the sum of the first ‘n’ natural numbers and returning it.
Example:
Input: ‘n’ = 3*/

#include<iostream>
using namespace std;

int sum(int n)
{
    if(n<=1){
        return n;
    }
    return n+sum(n-1);
}
int main(){
    int n = 3;
    cout<<sum(n)<<endl;

    return 0;
}