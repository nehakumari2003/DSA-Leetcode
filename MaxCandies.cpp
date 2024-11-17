#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int maxCandies(int n, vector<int>& A, int M){
    int candiesBought = 0 ;

    // Sort the candy prices in ascending order to prioritize cheaper candies
    sort(A.begin() , A.end());
    for(int i = 0 ; i < n ; i++){
        if(A[i]%5 == 0){
            candiesBought++;
        }
        else if(M >= A[i]){
            M-= A[i];
            candiesBought++;
        }
        else{
            break;
        }
            
    }
    return candiesBought;
}

