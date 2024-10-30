#include <iostream>
#include <cstring>
using namespace std;

int OperationsBinaryString(const char* str) {
    if(str == NULL){
        return -1;
    }
    int n = strlen(str);
    int result = str[0] - '0';
    for(int i = 1 ; i < n ; i += 2 ){
        char operation = str[i];
        char nextDigit = str[i+1] - '0';

        if(result == 'A'){
            result = result & nextDigit;
        }
        else if(result == 'B'){
             result = result | nextDigit;
        }
        else if(result == 'C'){
           result = result ^ nextDigit;
        }
    }
    return result;

}
int main() {
   
    char str[] = "1C0C1C1A0B1";
    
    int result = OperationsBinaryString(str);
    cout << result << endl; 
    
    return 0;
}