// Leetcode 1011

// A conveyor belt has packages that must be shipped from one port to another within days days.

// The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

// Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

#include <iostream>
#include <vector>
#include <numeric>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countDays(vector<int>& weights, int capacity) {
        int days = 1;
        int currentLoad = 0;

        for (int weight : weights) {
            if (weight > capacity) return INT_MAX;
            if (currentLoad + weight > capacity) {
                days++;
                currentLoad = 0;
            }
            currentLoad += weight;
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int answer = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int neededDays = countDays(weights, mid);

            if (neededDays <= days) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return answer;
    }
};

int main() {
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;
    Solution sol;
    int result = sol.shipWithinDays(weights, days);
    cout << result << endl;
    return 0;
}
