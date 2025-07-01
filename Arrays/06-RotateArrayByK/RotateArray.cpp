#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Approach 1
    void solve(vector<int>& nums, int n) {
        int last_ele = nums[n - 1];
        int temp1 = nums[0];
        int temp2 = nums[0];
        for (int i = 1; i < n; i++) {
            temp2 = nums[i];
            nums[i] = temp1;
            temp1 = temp2;
        }
        nums[0] = last_ele;
    }

    void rotate(vector<int>& nums, int k) {
        
        // Approach 1
        // int n = nums.size();
        // for (int i = 0; i < k; i++) {
        //     solve(nums, n);
        // }

        // Optimal Approach
        k=k%nums.size();
        reverse(nums.begin(),nums.begin()+(nums.size()-k));

        reverse(nums.begin()+(nums.size()-k),nums.end());
    
        reverse(nums.begin(),nums.end());
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    Solution sol;
    sol.rotate(nums, k);

    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
