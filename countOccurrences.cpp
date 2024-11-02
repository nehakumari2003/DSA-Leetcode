#include <iostream>
#include<vector>
#include<unordered_map>

using namespace std;

void countOccurrences(vector<int> &arr){
    unordered_map<int,int> elementCount;

    for(int i = 0 ; i < arr.size() ; i++){
        elementCount[arr[i]]++;
    }
    for (int i = 0; i < elementCount.size(); i++) {
        cout << elementCount.begin()->first << " occurs " << elementCount.begin()->second << " times." << endl;
        elementCount.erase(elementCount.begin());
    }
}