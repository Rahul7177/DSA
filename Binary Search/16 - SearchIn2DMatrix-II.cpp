#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0, col = m - 1;
        while (row < n && col >= 0) {
            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] < target)
                row++;
            else
                col--;
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1,4,7,11,15},
        {2,5,8,12,19},
        {3,6,9,16,22},
        {10,13,14,17,24},
        {18,21,23,26,30}
    };
    int target1 = 5;
    int target2 = 20;
    bool result1 = sol.searchMatrix(matrix, target1);
    bool result2 = sol.searchMatrix(matrix, target2);
    cout << (result1 ? "true" : "false") << endl;
    cout << (result2 ? "true" : "false") << endl;
    return 0;
}
