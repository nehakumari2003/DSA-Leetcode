#include <iostream>
#include <vector>
using namespace std;

int countDecreasingDays(const vector<int>& prices) {
    int countDays = 0;
    for(int i = 1; i < prices.size(); i++) { 
        if(prices[i] < prices[i - 1]) { 
            countDays++;
        }
    }
    return countDays;
}

int main() {
    int N;
    cout << "Enter the number of days: ";
    cin >> N;

    vector<int> prices(N);
    cout << "Enter the stock prices for each day: ";
    for (int i = 0; i < N; ++i) {
        cin >> prices[i];
    }

    int result = countDecreasingDays(prices);
    cout << "Total number of days with a decrease in stock price: " << result << endl;

    return 0;
}
