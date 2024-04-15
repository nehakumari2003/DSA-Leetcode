/*Problem statement
You are given a positive integer ‘n’.
Your task is to find and return its square root. If ‘n’ is not a perfect square, then return the floor value of sqrt(n).*/
#include<bits/stdc++.h>
using namespace std;

int floorSqr(int &n){
    int low = -1, high = n;
    int ans = 1;
    while(low <= high){
        long long mid  = (low+high)/2;
        long long val = mid * mid;
        if (val <= (long long)(n)) {
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid -1;
        }

    }
    return ans;
}
int main(){
    int n = 16;
    int Result = floorSqr(n);
    cout << "The square is : " << Result<< endl;
    return 0;
}