#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;


vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
	if (intervals.empty()) {
		return vector<vector<int>>();
	}

	sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
		return a[0] < b[0];
	});

	stack<vector<int>> mergedStack;
	mergedStack.push(intervals[0]);

	for (int i = 1; i < intervals.size(); i++) {
		vector<int> current = intervals[i];
		vector<int>& top = mergedStack.top();

		if (current[0] <= top[1]) {
			
			top[1] = max(top[1], current[1]);
		} else {
			
			mergedStack.push(current);
		}
	}

	
	vector<vector<int>> mergedIntervals;
	while (!mergedStack.empty()) {
		mergedIntervals.insert(mergedIntervals.begin(), mergedStack.top());
		mergedStack.pop();
	}

	return mergedIntervals;
}

int main() {
	vector<vector<int>> intervals = {{6, 8}, {1, 9}, {2, 4}, {4, 7}};
	vector<vector<int>> merged = overlappedInterval(intervals);

	cout << "The Merged Intervals are: ";
	for (const vector<int>& interval : merged) {
		cout << "[" << interval[0] << ", " << interval[1] << "] ";
	}
	cout << endl;

	return 0;
}

