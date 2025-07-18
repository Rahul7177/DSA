#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> allCombinations;
        vector<int> currentCombination;
        findCombinations(candidates, target, 0, currentCombination, 0, allCombinations);
        return allCombinations;     
    }

private:
    void findCombinations(vector<int>& candidates, int target, int index, 
                          vector<int>& currentCombination, int currentSum, 
                          vector<vector<int>>& allCombinations) {
        // If the current sum equals the target, store the combination
        if (currentSum == target) {
            allCombinations.push_back(currentCombination);
            return;
        }

        // If current sum exceeds target or index is out of bounds, stop
        if (currentSum > target || index >= candidates.size()) {
            return;
        }

        // Choose the number at the current index
        currentCombination.push_back(candidates[index]);
        findCombinations(candidates, target, index, currentCombination, currentSum + candidates[index], allCombinations);

        // Backtrack: remove the last number and try the next one
        currentCombination.pop_back();
        findCombinations(candidates, target, index + 1, currentCombination, currentSum, allCombinations);
    }
};

int main() {
    Solution sol;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result = sol.combinationSum(candidates, target);
    for (const auto& comb : result) {
        for (int num : comb) cout << num << " ";
        cout << endl;
    }

    return 0;
}
