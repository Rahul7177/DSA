#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto i : nums) mp[i]++;
        bool flag = false;
        for(auto i : mp){
            if(i.second >= 2) return true;
        }
        return flag;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 1};

    Solution sol;
    bool result = sol.containsDuplicate(nums);

    if(result)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}
