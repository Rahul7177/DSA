#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[mid + 1]) {
                high = mid; // peak in left half (including mid)
            } else {
                low = mid + 1; // peak in right half
            }
        }

        return low; // low == high is a peak index
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {1, 2, 3, 1};
    int peakIndex1 = sol.findPeakElement(nums1);
    cout << "Peak index in nums1: " << peakIndex1 << ", Value: " << nums1[peakIndex1] << endl;

    // Test Case 2
    vector<int> nums2 = {1, 2, 1, 3, 5, 6, 4};
    int peakIndex2 = sol.findPeakElement(nums2);
    cout << "Peak index in nums2: " << peakIndex2 << ", Value: " << nums2[peakIndex2] << endl;

    // Test Case 3 (edge case: descending)
    vector<int> nums3 = {5, 4, 3, 2, 1};
    int peakIndex3 = sol.findPeakElement(nums3);
    cout << "Peak index in nums3: " << peakIndex3 << ", Value: " << nums3[peakIndex3] << endl;

    return 0;
}
