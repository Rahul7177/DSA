#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    pair<int, int> getMinMax(vector<int> arr) {
        sort(arr.begin(), arr.end());
        return {arr[0], arr[arr.size() - 1]};
    }
};

int main() {
    vector<int> arr = {3, 1, 5, 2, 4};

    Solution sol;
    pair<int, int> result = sol.getMinMax(arr);

    cout << result.first << " " << result.second << endl;

    return 0;
}
