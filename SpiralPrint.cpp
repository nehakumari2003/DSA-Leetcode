/*Given an m x n matrix, return all elements of the matrix in spiral order.*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row = matrix.size();
        if (row == 0) return ans; // Handle empty matrix case
        int col = matrix[0].size();
        int count = 0;
        int total = row * col;

        int startingRow = 0;
        int startingCol = 0;
        int endingRow = row - 1;
        int endingCol = col - 1;

        while (count < total) {
            // Print starting row
            for (int index = startingCol; index <= endingCol && count < total; index++) {
                ans.push_back(matrix[startingRow][index]);
                count++;
            }
            startingRow++;

            // Print ending column
            for (int index = startingRow; count < total && index <= endingRow; index++) {
                ans.push_back(matrix[index][endingCol]);
                count++;
            }
            endingCol--;

            // Print ending row
            for (int index = endingCol; count < total && index >= startingCol; index--) {
                ans.push_back(matrix[endingRow][index]);
                count++;
            }
            endingRow--;

            // Print starting column 
            for (int index = endingRow; count < total && index >= startingRow; index--) {
                ans.push_back(matrix[index][startingCol]);
                count++;
            }
            startingCol++;
        }
        return ans;
    }
};

int main() {
    
    Solution solution;
    vector<vector<int>> matrix = {{1, 2, 3},
                                  {4, 5, 6},
                                  {7, 8, 9}};

    vector<int> result = solution.spiralOrder(matrix);

    
    cout << "Spiral Order: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
