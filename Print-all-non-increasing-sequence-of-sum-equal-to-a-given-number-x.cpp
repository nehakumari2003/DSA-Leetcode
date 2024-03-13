// C++ program to generate all non-increasing

#include<bits/stdc++.h>
using namespace std;


void printArr(int arr[], int n)
{
	for(int i = 0; i < n; i++)
	cout << arr[i] << " ";
	cout << endl;
}

void generateUtil(int x, int arr[], int curr_sum,
									int curr_idx)
{
	
if (curr_sum == x)
{
	printArr(arr, curr_idx);
	return;
}

int num = 1;

while (num <= x - curr_sum &&
		(curr_idx == 0 || 
		num <= arr[curr_idx - 1]))
{
		
	
	arr[curr_idx] = num;

	
	generateUtil(x, arr, curr_sum + num,
							curr_idx + 1);

	
	num++;
}
}

void generate(int x)
{
	
	int arr[x]; 
	generateUtil(x, arr, 0, 0);
}

int main()
{
	int x = 5;
	generate(x);
	return 0;
}
