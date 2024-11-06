#include <iostream>
#include <algorithm>
#include <vector>

int findDividendIndex(vector<int>& A, int D, int Q, int R, int N) {
    int dividend = D * Q + R;
    for (int i = 0; i < N; i++) {
        if (A[i] == dividend) {
            return i;  // Return the index if the dividend is found
        }
    }
    return -1;  
}
