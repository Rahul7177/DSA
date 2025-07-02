#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                ans = i;
                break;
            }
        }
        if (nums[n - 1] == n)
            return ans;
        return n;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 0, 1};

    cout << "Original array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    int result = sol.missingNumber(nums);

    cout << "Missing number: " << result << endl;

    return 0;
}
