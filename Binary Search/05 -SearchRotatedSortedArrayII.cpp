#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
                return true;

            if ((nums[l] == nums[mid]) && (nums[r] == nums[mid])) {
                l++;
                r--;
            } else if (nums[l] <= nums[mid]) {
                if ((nums[l] <= target) && (nums[mid] > target))
                    r = mid - 1;
                else
                    l = mid + 1;
            } else {
                if ((nums[mid] < target) && (nums[r] >= target))
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return false;
    }
};

int main() {
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target = 0;
    Solution sol;
    bool found = sol.search(nums, target);
    cout << (found ? "true" : "false") << endl;
    return 0;
}
