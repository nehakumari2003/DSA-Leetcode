// C++ Program to print a triangle star patter 
#include <iostream> 
using namespace std; 

int main() 
{ 
	int rows; 

	rows = 5; 

	for (int i = 1; i <= rows; i++) { 
		for (int j = 1; j <= i; j++) { 
			cout << "*"; 
		} 
		cout << endl; 
	} 

	return 0; 
}
