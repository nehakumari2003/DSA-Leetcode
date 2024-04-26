/*A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.

Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].

You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.*/
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int findMaxIndex(vector<vector<int>> &g, int n, int m, int col) {
    int maxvalue = -1;
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (g[i][col] > maxvalue) {
            maxvalue = g[i][col];
            index = i;
        }
    }
    return index;
}

vector<int> findPeakGrid(vector<vector<int>> &g) {
    int n = g.size();
    int m = g[0].size();
    int low = 0, high = m - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int maxRowIndex = findMaxIndex(g, n, m, mid);
        int left = (mid - 1 >= 0) ? g[maxRowIndex][mid - 1] : -1;
        int right = (mid + 1 < m) ? g[maxRowIndex][mid + 1] : -1;
        if (g[maxRowIndex][mid] > left && g[maxRowIndex][mid] > right) {
            return {maxRowIndex, mid};
        } else if (g[maxRowIndex][mid] < left) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return {-1, -1};
}
int main() {
    vector<vector<int>> grid = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    vector<int> peak = findPeakGrid(grid);
    if (peak[0] != -1 && peak[1] != -1) {
        cout << "Peak element found at position: (" << peak[0] << ", " << peak[1] << ")" << endl;
    } else {
        cout << "No peak element found in the grid." << endl;
    }

    return 0;
}
