// URL: https://leetcode.com/problems/combination-sum-iii/description/

// 216. Combination Sum III

// Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

// 	Only numbers 1 through 9 are used.
// 	Each number is used at most once.

// Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

//  
// Example 1:

// Input: k = 3, n = 7
// Output: [[1,2,4]]
// Explanation:
// 1 + 2 + 4 = 7
// There are no other valid combinations.

// Example 2:

// Input: k = 3, n = 9
// Output: [[1,2,6],[1,3,5],[2,3,4]]
// Explanation:
// 1 + 2 + 6 = 9
// 1 + 3 + 5 = 9
// 2 + 3 + 4 = 9
// There are no other valid combinations.

// Example 3:

// Input: k = 4, n = 1
// Output: []
// Explanation: There are no valid combinations.
// Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.

//  
// Constraints:

// 	2 <= k <= 9
// 	1 <= n <= 60


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solve(int num, int k, int n, int currentSum, vector<int>& currentSet, vector<vector<int>>& res) {
        if (currentSum == n && currentSet.size() == k) {
            res.push_back(currentSet);
            return;
        }

        if (num > 9 || currentSet.size() > k || currentSum > n) {
            return;
        }

        currentSet.push_back(num);
        solve(num + 1, k, n, currentSum + num, currentSet, res);

        currentSet.pop_back();
        solve(num + 1, k, n, currentSum, currentSet, res);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        int num = 1;
        int currentSum = 0;
        vector<int> currentSet;
        vector<vector<int>> res;

        solve(num, k, n, currentSum, currentSet, res);
        return res;
    }
};

int main() {
    Solution sol;
    int k = 3, n = 7;
    vector<vector<int>> result = sol.combinationSum3(k, n);

    cout << "Combinations of " << k << " numbers summing to " << n << ":\n";
    for (const auto& comb : result) {
        cout << "[ ";
        for (int num : comb) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}