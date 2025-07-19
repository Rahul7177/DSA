// URL: https://leetcode.com/problems/subsets-ii/description/

// 90. Subsets II

// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

// 
// Example 1:
// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
// Example 2:
// Input: nums = [0]
// Output: [[],[0]]

// 
// Constraints:

// 	1 <= nums.length <= 10
// 	-10 <= nums[i] <= 10

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  void solve(vector<int>& nums, int index, vector<int>& currentSet, vector<vector<int>>& powerSet) {
    powerSet.push_back(currentSet);

    for (int i = index; i < nums.size(); ++i) {
      // Skip duplicates at the same recursive level
      if (i > index && nums[i] == nums[i - 1]) continue;

      currentSet.push_back(nums[i]);
      solve(nums, i + 1, currentSet, powerSet);
      currentSet.pop_back(); // Backtrack
    }
  }

  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<int> currentSet;
    vector<vector<int>> powerSet;

    sort(nums.begin(), nums.end()); // Sort to handle duplicates
    solve(nums, 0, currentSet, powerSet);

    return powerSet;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {1, 2, 2};

  vector<vector<int>> result = sol.subsetsWithDup(nums);

  cout << "All unique subsets:\n";
  for (const auto& subset : result) {
    cout << "[ ";
    for (int num : subset) {
      cout << num << " ";
    }
    cout << "]\n";
  }

  return 0;
}
