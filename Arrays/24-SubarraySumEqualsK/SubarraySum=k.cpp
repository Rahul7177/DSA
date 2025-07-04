#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, count = 0;
        unordered_map<int, int> prefixSum;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum == k) {
                count++;
            }
            int val = sum - k;
            if (prefixSum.find(val) != prefixSum.end()) {
                count += prefixSum[val];
            }
            prefixSum[sum]++;
        }
        return count;
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    int k = 3;
    Solution sol;
    int result = sol.subarraySum(nums, k);
    cout << result << endl;
    return 0;
}
