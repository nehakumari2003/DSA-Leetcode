#include <iostream> 
using namespace std; 

 
void hourglass(int rows) 
{ 

	 
	for (int i = 0; i < 2 * rows - 1; i++) { 

		 
		int comp; 
		if (i < rows) { 
			comp = 2 * i + 1; 
		} 
		else { 
			comp = 2 * (2 * rows - i) - 3; 
		} 

		
		for (int j = 0; j < comp; j++) { 
			cout << ' '; 
		} 

		 
		for (int k = 0; k < 2 * rows - comp; k++) { 
			cout << "* "; 
		} 
		cout << '\n'; 
	} 
} 

int main() 
{ 
	hourglass(5); 
	return 0; 
}
