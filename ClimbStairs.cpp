/*You have been given a number of stairs. Initially, you are at the 0th stair, and you need to reach the Nth stair. Each time you can either climb one step or two steps. You are supposed to return the number of distinct ways in which you can climb from the 0th step to Nth step.*/
#include <iostream>
using namespace std;

int countDistinctWays(int nStairs) {
    if (nStairs == 0) {
        return 1;  
    }
    if (nStairs == 1) {
        return 1;  
    }
    if (nStairs == 2) {
        return 2;  
    }

   
    return countDistinctWays(nStairs - 1) + countDistinctWays(nStairs - 2);
}

int main() {
    int nStairs;
    cout << "Enter the number of stairs: ";
    cin >> nStairs;

    int ways = countDistinctWays(nStairs);
    cout << "Distinct ways to climb " << nStairs << " stairs: " << ways << std::endl;

    return 0;
}
