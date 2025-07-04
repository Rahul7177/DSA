#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1)
            return 0;

        int max_profit = 0;
        int i = 0;

        for (int j = 1; j < n; j++) {
            if (prices[j] > prices[i]) {
                max_profit = max(max_profit, prices[j] - prices[i]);
            } else {
                i = j;
            }
        }

        return max_profit;
    }
};

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    Solution sol;
    int result = sol.maxProfit(prices);
    cout << result << endl;
    return 0;
}
