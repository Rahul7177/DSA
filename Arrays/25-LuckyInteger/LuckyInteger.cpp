// Given an array of integers arr, a lucky integer is an integer that has a frequency in the array equal to its value.

// Return the largest lucky integer in the array. If there is no lucky integer return -1.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();
        int ans = -1;
        unordered_map<int, int> mp;
        for (auto i : arr) {
            mp[i]++;
        }

        for (auto m : mp) {
            if (m.first == m.second) {
                ans = max(ans, m.first);
            }
        }

        return ans;
    }
};

int main() {
    vector<int> arr = {2, 2, 3, 4};
    Solution sol;
    int result = sol.findLucky(arr);
    cout << result << endl;
    return 0;
}
