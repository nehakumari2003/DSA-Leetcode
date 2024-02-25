#include <climits> 
#include <iostream> 
using namespace std; 

void print2Smallest(int arr[], int n) 
{ 
	int first, second; 

	if (n < 2) { 
		cout << " Invalid Input "; 
		return; 
	} 

	first = second = INT_MAX; 
	for (int i = 0; i < n; i++) { 
		
		if (arr[i] < first) { 
			second = first; 
			first = arr[i]; 
		} 

		else if (arr[i] < second && arr[i] != first) 
			second = arr[i]; 
	} 
	if (second == INT_MAX) 
		cout << "There is no second smallest element\n"; 
	else
		cout << " Second smallest element is " << second 
			<< endl; 
} 

int main() 
{ 
	int arr[] = { 21, 3, 15, 41, 34, 10 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	print2Smallest(arr, n); 

	return 0; 
}
