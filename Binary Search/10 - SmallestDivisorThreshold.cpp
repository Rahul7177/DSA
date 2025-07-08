// LEETCODE 1283

// Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

// Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

// The test cases are generated so that there will be an answer.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int result = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int sum = 0;
            for (int num : nums) {
                sum += (num + mid - 1) / mid; // integer ceiling of num/mid
            }

            if (sum <= threshold) {
                result = mid;
                high = mid - 1; // try smaller divisor
            } else {
                low = mid + 1;  // need larger divisor
            }
        }

        return result;
    }
};

// -------- Driver Code --------
int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 5, 9};
    int threshold1 = 6;
    cout << "Minimum divisor: " << sol.smallestDivisor(nums1, threshold1) << endl; // Output: 5

    vector<int> nums2 = {44, 22, 33, 11, 1};
    int threshold2 = 5;
    cout << "Minimum divisor: " << sol.smallestDivisor(nums2, threshold2) << endl; // Output: 44

    return 0;
}
