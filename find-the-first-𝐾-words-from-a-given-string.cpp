#include <iostream>
#include <string>
using namespace std;

string getFirstKWords(const string& str, int K){
    string result;
    int wordcount = 0;
    string word;

    for(char ch : str){
        if(ch == ' '){
            if(wordcount < K){
                result += word + " ";
                word.clear();
                wordcount++;
            }
        }
        else{
            word += ch;
        }
    }
    if(wordcount < K){
        result += word;
    }
    return result;      
}  
