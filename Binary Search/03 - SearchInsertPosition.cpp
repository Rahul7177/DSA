// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1;
        int mid;
        while (s <= e) {
            mid = s + (e - s) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return s;
    }
};

int main() {
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    Solution sol;
    int result = sol.searchInsert(nums, target);
    cout << result << endl;
    return 0;
}
