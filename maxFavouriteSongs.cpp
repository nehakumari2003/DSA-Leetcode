#include <iostream>
#include <string>
using namespace std;

int maxFavouriteSongs(const string& S, int k) {
    int maxcount = 0;
    int currentCount = 0 ;
    for(int i = 0 ; i < k ; i++){
        if(S[i] == 'a'){
            currentCount++;
        }
    }
    maxcount = currentCount;

    for(int i = k ; i<S.size() ; i++){
        if(S[i-k] == 'a'){
            currentCount--;
        }
        if(S[i] == 'a'){
            currentCount++;
        }
        if(currentCount > maxcount){
            maxcount = currentCount;
        }
    }
    return maxcount;
}

int main() {
    string S;
    int k;
    
    cout << "Enter the string of songs: ";
    cin >> S;
    
    cout << "Enter the length of the playlist (k): ";
    cin >> k;

    int result = maxFavouriteSongs(S, k);
    cout << "Maximum number of favourite songs ('a') in a playlist of length " << k << " is: " << result << endl;

    return 0;
}