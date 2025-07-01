#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ans; 
        int i = 0;
        int j = 0;
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] < nums2[j]){
                i++;
            }
            else if(nums1[i] > nums2[j]){
                j++;
            }
            else{
                ans.push_back(nums1[i]);
                while(i < nums1.size()-1 && nums1[i] == nums1[i+1]){
                    i++;
                }
                while(j < nums2.size()-1 && nums2[j] == nums2[j+1]){
                    j++;
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums1 = {1, 2, 2, 3};
    vector<int> nums2 = {2, 2, 3, 4};

    Solution sol;
    vector<int> result = sol.intersection(nums1, nums2);

    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
