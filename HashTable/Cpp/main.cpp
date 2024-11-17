#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        vector<vector<int>> result = {};

        while (i < nums.size() && nums[i] <= 0) {
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                // Target found
                if (sum == 0) {
                    result.push_back({i, left, right});
                } 

                if (sum <= 0) {
                    // Make the sum bigger by increasing left 
                    left++;
                    while (left < nums.size() && nums[left - 1] == nums[left]) {
                        left++;
                    }
                } else {
                    // Make the sum smaller by decreasing right
                    right--;
                    // Continue decreasing to avoid checking duplicates
                    while (right > 0 && nums[right + 1] == nums[right]) {
                        right--;
                    }
                }
            }

            i++;
            while (nums[i - 1] == nums[i]) {
                i++;
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {0, 0, 0, 0};
    vector<vector<int>> result = s.threeSum(nums);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}