// URL: https://leetcode.com/problems/subsets/description/

// 78. Subsets
// Given an integer array nums of unique elements, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

// Example 1:
// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

// Example 2:
// Input: nums = [0]
// Output: [[],[0]]

// Constraints:
// 	1 <= nums.length <= 10
// 	-10 <= nums[i] <= 10
// 	All the numbers ofnums are unique.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void solve(vector<int> &nums, int index, vector<int> &currentSet, vector<vector<int>> &powerSet)
    {
        if (index >= nums.size())
        {
            powerSet.push_back(currentSet);
            return;
        }

        // Include the current index element
        currentSet.push_back(nums[index]);
        solve(nums, index + 1, currentSet, powerSet);

        // Backtrack the last element pushed in
        currentSet.pop_back();

        // Exclude the current index element
        solve(nums, index + 1, currentSet, powerSet);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> currentSet;
        vector<vector<int>> powerSet;
        int index = 0;

        solve(nums, index, currentSet, powerSet);
        return powerSet;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> result = sol.subsets(nums);

    cout << "All subsets:\n";
    for (const auto &subset : result)
    {
        cout << "[ ";
        for (int num : subset)
        {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
