#include<iostream>
using namespace std;

int main(){
        string str ;
        cout << "enter a string " << endl;
        cin >>  str;

        for(int i = str.length()-1 ; i >=0 ; i--){
            cout<< str[i];
        }
    return 0;

}