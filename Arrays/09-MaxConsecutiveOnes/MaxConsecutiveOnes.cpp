#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                maxi++;
                ans = max(ans, maxi);
            } else {
                maxi = 0;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 0, 1, 1, 1};

    cout << "Input array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    int result = sol.findMaxConsecutiveOnes(nums);

    cout << "Maximum consecutive ones: " << result << endl;

    return 0;
}
