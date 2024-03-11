/*Problem statement
You are given an integer ‘n’.



Your task is to return an array containing integers from ‘n’ to ‘1’ (in decreasing order) without using loops.

*/

#include <iostream>
#include <vector>

using namespace std;

void rec(int x, vector<int>& ans) {
    if(x == 0) {
        return;
    }
    ans.push_back(x);
    rec(x-1, ans);
}

vector<int> printNos(int x) {
    vector<int> ans;
    rec(x, ans);
    return ans;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    vector<int> result = printNos(n);

    cout << "Printing numbers from " << n << " to 1: ";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
