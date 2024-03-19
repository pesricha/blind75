#include<iostream>
#include<vector>
#include<algorithm>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        const int length = nums.size();

        if (length == 1) return nums[0];

        int prev1 = 0, prev2 = 0;

        for (int i = 0; i < length-1 ;i++)
        {
            int temp = prev1;
            prev1 = std::max(prev1, prev2 + nums[i]);
            prev2 = temp;
        }

        int max1 = prev1;
        prev1 =0; prev2 =0;

        for (int i= 1 ; i < length ; i++)
        {
            int temp = prev1;
            prev1 = std::max(prev1, prev2 + nums[i]);
            prev2 = temp;
        }

        return std::max(prev1, max1);
    }
};