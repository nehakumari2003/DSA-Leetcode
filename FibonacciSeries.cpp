/*The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).

 */
#include <iostream>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        int ans = fib(n - 1) + fib(n - 2);
        return ans;
    }
};

int main() {
    Solution solution;

    
    int n = 10;
    int fibonacciNumber = solution.fib(n);

    std::cout << "Fibonacci number at position " << n << ": " << fibonacciNumber << std::endl;

    return 0;
}
