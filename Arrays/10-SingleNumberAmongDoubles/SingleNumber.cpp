#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (auto x : nums)
            ans ^= x;
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 1, 2, 1, 2};

    cout << "Input array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    int result = sol.singleNumber(nums);

    cout << "Single number: " << result << endl;

    return 0;
}
