

#include "bits/stdc++.h"
using namespace std;


struct interval {
	int start, end;
};


bool compareinterval(interval i1, interval i2)
{
	return (i1.start < i2.start);
}


void findFreeinterval(interval arr[], int N)
{

	
	if (N <= 0) {
		return;
	}

	
	vector<pair<int, int> > P;

	
	sort(arr, arr + N, compareinterval);

	
	for (int i = 1; i < N; i++) {

		
		int prevEnd = arr[i - 1].end;

		
		int currStart = arr[i].start;

		
		if (prevEnd < currStart) {
			P.push_back({ prevEnd,
						currStart });
		}
	}

	
	for (auto& it : P) {
		cout << "[" << it.first << ", "
			<< it.second << "]" << endl;
	}
}


int main()
{

	
	interval arr[] = { { 1, 3 },
					{ 2, 4 },
					{ 3, 5 },
					{ 7, 9 } };

	int N = sizeof(arr) / sizeof(arr[0]);

	
	findFreeinterval(arr, N);
	return 0;
}
