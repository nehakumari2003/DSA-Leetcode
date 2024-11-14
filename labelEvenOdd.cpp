#include <iostream>
#include <vector>
#include <string>
using namespace std;

string labelEvenOdd(const vector<int> &A){
    string result = "";
    for(int i = 0 ; i < A.size() ; i++){
        if(A[i] %  2 == 0){
            result = result + "even";
        }
        else{
            result = result+"odd";
        }
    }
    if(!result.empty()){
        result.pop_back();
    }
    return result;
}
int main() {
    int N;
    cout << "Enter the number of elements in the array: ";
    cin >> N;
    
    vector<int> A(N);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    string result = labelEvenOdd(A);
    cout << "Labels for the array: " << result << endl;

    return 0;
}