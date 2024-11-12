#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isvowel(char c){
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int factorial (int n) {
    if(n == 0 || n ==1){
        return 1;
    }
    int result = 1;
    for(int i = 2 ; i <= n ; i++){
        result *= i;
    }
    return result;
}

int countConsonantPermutations(const string& S){
    int consonantCount = 0;
    for(char c : S)
    if(!isvowel(c) && isalpha(c)){
        consonantCount ++;
    }
    if(consonantCount == 0){
        return 0;
    }
    return factorial(consonantCount);

}
int main() {
    string S;
    cout << "Enter the string: ";
    cin >> S;
    
    int result = countConsonantPermutations(S);
    cout << "Count of permutations with fixed vowels: " << result << endl;
    
    return 0;
}