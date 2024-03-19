#include<iostream>
#include<vector>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        const int n = nums.size();
        int best_sum = INT16_MIN;
        int curr_sum = 0;

        for (int i = 0; i < n ; i++)
        {
            curr_sum = std::max(nums[i], curr_sum + nums[i]);
            best_sum = std::max(best_sum, curr_sum);
        }
        return best_sum;
    }
};