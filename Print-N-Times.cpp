/*You are given an integer ‘n’.
Print “Coding Ninjas ” ‘n’ times, without using a loop.*/

#include<iostream>
#include<vector>

using namespace std;

vector<string> printNTimes(int n) {
	vector<string> ans;
	for(int i = 0 ;  i<n ; i++){
		ans.push_back("Coding Ninjas");
	}
	return ans;
}
int main(){
    int n;
    cout << "Enter the value of n  : "<< endl;
    cin>> n;

    vector<string> Result = printNTimes(n);
    cout << "Printing "<< n << "times : " << endl;
    for(const auto &str : Result){
        cout << str <<endl;

    }
    return 0;

}