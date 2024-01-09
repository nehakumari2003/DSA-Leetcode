/*Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 */

class Solution {
public:
    long long int binarySearch(int n){
        int s = 0;
        int e =n;
        long long int mid = s+(e-s)/2;
        long long int ans = -1;
        while(s<=e){
            long long int square = mid*mid;
            if(square ==n){
                return mid;
            }
            if(square<n){
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            mid=s+(e-s)/2;

        }
        return ans;
    }
    int mySqrt(int x) {
        return binarySearch(x);
    }
};