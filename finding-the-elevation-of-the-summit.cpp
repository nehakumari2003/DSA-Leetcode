#include <iostream>
#include <vector>
using namespace std;

int findSummitElevation(const vector<int>& A){
    int max = A[0];

    for(int i = 0 ; i < A.size() ; i++){
        if(A[i] > max){
            max = A[i];
        }
    }
    return max;
}
int main() {
    int N;
    cout << "Enter the number of elevations: ";
    cin >> N;

    vector<int> A(N);
    cout << "Enter the elevations: ";
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int summitElevation = findSummitElevation(A);
    cout << "The elevation of the summit is: " << summitElevation << endl;

    return 0;
}