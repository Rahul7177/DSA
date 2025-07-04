#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // Better Approach : TC: O(N^2) SC: O(M+N)
    // void setZeroes(vector<vector<int>>& matrix) {
    //     int m = matrix.size();
    //     int n = matrix[0].size();

    //     vector<bool> rows(m, false);
    //     vector<bool> cols(n, false);

    //     for (int i = 0; i < m; i++) {
    //         for (int j = 0; j < n; j++) {
    //             if (matrix[i][j] == 0) {
    //                 rows[i] = true;
    //                 cols[j] = true;
    //             }
    //         }
    //     }

    //     for (int i = 0; i < m; i++) {
    //         if (rows[i]) {
    //             for (int j = 0; j < n; j++) {
    //                 matrix[i][j] = 0;
    //             }
    //         }
    //     }

    //     for (int j = 0; j < n; j++) {
    //         if (cols[j]) {
    //             for (int i = 0; i < m; i++) {
    //                 matrix[i][j] = 0;
    //             }
    //         }
    //     }
    // }


    //Optimal Approach TC: O(N^2) SC: O(1)
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool firstRowZero = false;
        bool firstColZero = false;

        for(int i = 0; i < m; i++) {
            if(matrix[i][0] == 0) 
                firstColZero = true;
        }

        for(int j = 0; j < n; j++) {
            if(matrix[0][j] == 0) 
                firstRowZero = true;
        }

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if(firstRowZero) {
            for(int j = 0; j < n; j++) 
                matrix[0][j] = 0;
        }

        if(firstColZero) {
            for(int i = 0; i < m; i++) 
                matrix[i][0] = 0;
        }
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    Solution sol;
    sol.setZeroes(matrix);

    for(auto& row : matrix) {
        for(int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
