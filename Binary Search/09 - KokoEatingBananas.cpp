// LEETCODE 875

// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

// Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

// Return the minimum integer k such that she can eat all the bananas within h hours.


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int answer = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canEatAll(piles, h, mid)) {
                answer = mid;
                right = mid - 1;  // Try a slower speed
            } else {
                left = mid + 1;   // Need a faster speed
            }
        }

        return answer;
    }

private:
    bool canEatAll(const vector<int>& piles, int h, int speed) {
        long long hours = 0;  // Use long long to avoid overflow
        for (int bananas : piles) {
            hours += ((long long)bananas + speed - 1) / speed;
            if (hours > h) return false; // Early exit if already over limit
        }
        return hours <= h;
    }
};

// ----------- Driver Code -----------
int main() {
    Solution sol;

    vector<int> piles1 = {3, 6, 7, 11};
    int h1 = 8;
    cout << "Minimum speed for piles1: " << sol.minEatingSpeed(piles1, h1) << endl;

    vector<int> piles2 = {30, 11, 23, 4, 20};
    int h2 = 5;
    cout << "Minimum speed for piles2: " << sol.minEatingSpeed(piles2, h2) << endl;

    vector<int> piles3 = {30, 11, 23, 4, 20};
    int h3 = 6;
    cout << "Minimum speed for piles3: " << sol.minEatingSpeed(piles3, h3) << endl;

    return 0;
}
