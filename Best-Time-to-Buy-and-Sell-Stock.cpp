/*You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int maxprofit = 0;
        int n = prices.size();
        for(int i = 0 ; i < n ; i++){
            int cost = prices[i] - mini;
            maxprofit = max(maxprofit, cost);
            mini = min(mini, prices[i]);
        }
        return maxprofit;
    }
};
int main(){
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int max_profit = sol.maxProfit(prices);
    cout << "Max profit : " << max_profit << endl;
    return 0;
}