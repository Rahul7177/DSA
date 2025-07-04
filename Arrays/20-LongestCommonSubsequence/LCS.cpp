// Longest Common Subsequence
// Given an array arr[] of non-negative integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        if (arr.empty()) return 0;
        sort(arr.begin(), arr.end());
        int maxi = 1;
        int length = 1;
        int curr = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] == curr) {
                continue;
            } else if (arr[i] == curr + 1) {
                length++;
                curr = arr[i];
            } else {
                maxi = max(maxi, length);
                length = 1;
                curr = arr[i];
            }
        }
        maxi = max(maxi, length);
        return maxi;
    }
};

int main() {
    vector<int> arr = {100, 4, 200, 1, 3, 2};
    Solution sol;
    int result = sol.longestConsecutive(arr);
    cout << result << endl;
    return 0;
}
