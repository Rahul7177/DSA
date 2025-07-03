#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int, int> mp;

        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int diff = target - num;
            if (mp.find(diff) != mp.end()) {
                return {mp[diff], i};
            }
            mp[num] = i;
        }

        return {};
    }
};

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    Solution sol;
    vector<int> result = sol.twoSum(nums, target);

    if (!result.empty()) {
        cout << result[0] << " " << result[1] << endl;
    } else {
        cout << "No two sum solution found." << endl;
    }

    return 0;
}
