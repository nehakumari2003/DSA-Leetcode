#include <iostream>
using namespace std;

int main() {
    int N, L;
    cin >> N >> L;


    if (N <= 0 || L <= 0 || L % 2 != 0 || N > L) {
        cout << "Invalid input" << endl;
        return 0;
    }


    int FL = (L - 2 * N) / 2;
    int TL = N - FL;


    if (FL >= 0 && TL >= 0) {
        cout << "FL = " << FL << endl;
        cout << "TL = " << TL << endl;
    } else {
        cout << "Invalid input" << endl;
    }

    return 0;
}
