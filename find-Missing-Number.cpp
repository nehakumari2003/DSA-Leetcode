#include <iostream>
#include <vector>
using namespace std;


int findMissingNumber(vector<int> arr) {
    int n = arr.size() + 1; // Total number of elements including the missing number
    int totalSum = n * (n + 1) / 2; 
    int actSum = 0;

    for (int i = 0; i < arr.size(); i++) {
        actSum += arr[i];
    }

    return totalSum - actSum;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array (excluding the missing number): ";
    cin >> n;

    vector<int> arr(n); 
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int missingNumber = findMissingNumber(arr);
    cout << "The missing number is: " << missingNumber << endl;

    return 0;
}
