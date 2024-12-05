#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int M, N; // Input for total stones on Mars and number of common stones
    cin >> M >> N;

    vector<int> arr(N);
    for(int i = 0 ; i< N ; i++){
        cin >> arr[i];
    }

    unordered_set<int> commonStones(arr.begin(), arr.end());

    int count =0;
    for(int i = 0 ; i< M ; i++){
        if(commonStones.find(i) == commonStones.end()){
            count++;
        }
    }
    return 0;
}