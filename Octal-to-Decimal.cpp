// C++ Program to convert ocatal to decimal 
#include <cmath> 
#include <iostream> 

using namespace std; 

int main() 
{ 
	int oct, dec = 0, place = 0; 
	 
	oct = 67; 

	int temp = oct; 
	while (temp) { 
		int lastDigit = temp % 10; 
		temp /= 10; 
		dec += lastDigit * pow(8, place); 
		++place; 
	} 

	cout << "Decimal equivalent is: " << dec << endl; 

	return 0; 
}
