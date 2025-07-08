// Leetcode 410

// Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

// Return the minimized largest sum of the split.

// A subarray is a contiguous part of the array.

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canSplit(nums, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }

private:
    bool canSplit(vector<int>& nums, int k, int maxSumAllowed) {
        int count = 1;
        int currSum = 0;
        for (int num : nums) {
            if (currSum + num > maxSumAllowed) {
                count++;
                currSum = num;
                if (count > k) return false;
            } else {
                currSum += num;
            }
        }
        return true;
    }
};

int main() {
    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;
    Solution sol;
    int result = sol.splitArray(nums, k);
    cout << result << endl;
    return 0;
}
