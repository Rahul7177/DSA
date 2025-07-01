//For Sorted Array

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[index] = nums[i];
                index++;
            }
        }
        return index;
    }
};

int main() {
    vector<int> nums = {1, 1, 2, 2, 3, 3, 4, 5};

    Solution sol;
    int k = sol.removeDuplicates(nums);

    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout << endl << k << endl;

    return 0;
}
