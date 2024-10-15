#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string findBestRhyme(const string & S, const vector<string> D){
    string BestRythm = "No Words";
    int maxLength = 0;

    //Iterate through each word of dictionary
    for(const string& word : D){
        int lenS = S.length();
        int lenword = word.length();
        int matchLen = 0;

        // Compare suffixes from the end of both strings
        for(int i = 1 ; i <= min(lenS , lenword) ; ++i){
            if(S[lenS - i] == word[lenword - i]){
                matchLen++;
            }
            else{
                break;
            }
        }
        if(matchLen > maxLength){
            maxLength = matchLen ;
            BestRythm = word;
        }
    }
    return BestRythm;

}
int main() {
    string S = "cave"; 
    vector<string> D = {"gave", "save", "brave", "grave", "rave", "slate", "late"}; 
    string result = findBestRhyme(S, D); 
    cout << "Best rhyming word: " << result << endl;
    return 0;
}