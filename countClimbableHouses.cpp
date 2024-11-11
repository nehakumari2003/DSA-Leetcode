#include <iostream>
#include <vector>
using namespace std;

int countClimbableHouses(const vector<int>& roofs) {
    int count = 0;
    for (int roof : roofs) {
        if (roof % 3 == 0) { 
            count++;
        }
    }
    return count;
}

int main() {
    int N;
    cout << "Enter the number of houses: ";
    cin >> N;

    vector<int> roofs(N);
    cout << "Enter the roof levels for each house: ";
    for (int i = 0; i < N; ++i) {
        cin >> roofs[i];
    }

    int result = countClimbableHouses(roofs);
    cout << "Number of houses Alice can climb: " << result << endl;

    return 0;
}
