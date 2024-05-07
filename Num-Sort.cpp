/*write a program to accept  numbers from the user till the user ZERO and store them in a list . After that arrange them in increasing order using bubble sort.*/
#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    vector<int> numbers;
    
    cout << "Enter numbers (separate by spaces, enter 0 to stop): ";
    for (int num = 0; cin >> num && num != 0; ) {
        numbers.push_back(num);
    }

    bubbleSort(numbers);

    cout << "Sorted list in ascending order: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
