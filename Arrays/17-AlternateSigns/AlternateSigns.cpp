// You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

// You should return the array of nums such that the the array follows the given conditions:

// Every consecutive pair of integers have opposite signs.
// For all integers with the same sign, the order in which they were present in nums is preserved.
// The rearranged array begins with a positive integer.
// Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> positive;
        vector<int> negative;

        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) {
                positive.push_back(i);
            } else {
                negative.push_back(i);
            }
        }

        vector<int> ans;
        for(int i = 0; i < n / 2; i++) {
            ans.push_back(nums[positive[i]]);
            ans.push_back(nums[negative[i]]);
        }

        return ans;
    }
};

int main() {
    vector<int> nums = {3, 1, -2, -5, 2, -4};
    Solution sol;
    vector<int> result = sol.rearrangeArray(nums);
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
