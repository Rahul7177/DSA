#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            // If middle element is greater than the rightmost,
            // then the minimum is in the right half
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } else {
                // Minimum could be at mid or in the left half
                high = mid;
            }
        }
        // When loop ends, low == high, pointing to the minimum
        return nums[low];
    }
};

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    Solution sol;
    int result = sol.findMin(nums);
    cout << result << endl;
    return 0;
}
