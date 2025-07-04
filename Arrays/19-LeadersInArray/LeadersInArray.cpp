// Leaders in Array
// You are given an array arr of positive integers. Your task is to find all the leaders in the array. An element is considered a leader if it is greater than or equal to all elements to its right. The rightmost element is always a leader.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> leaders(vector<int>& arr) {
        vector<int> ans;
        int n = arr.size();
        int mini = -1;
        for (int i = n - 1; i >= 0; --i) {
            if (arr[i] >= mini) {
                ans.push_back(arr[i]);
                mini = arr[i];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    Solution sol;
    vector<int> result = sol.leaders(arr);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
