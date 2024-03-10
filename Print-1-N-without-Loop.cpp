/*You are given an integer ‘n’.



Your task is to return an array containing integers from 1 to ‘n’ (in increasing order) without using loops.*/

#include <iostream>
#include <vector>

std::vector<int> printNos(int x) {
    std::vector<int> ans;
    for(int i = 1 ;  i<= x ; i++){
        ans.push_back(i);
    }
    return ans;
}

int main() {
    int x = 10;
    std::vector<int> result = printNos(x);
    
    std::cout << "Numbers from 1 to " << x << ": ";
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
