#include<iostream>
#include<vector>

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int ans = 0;
        for (auto num : nums)
        {
            ans = ans ^ num;
        }

        for (int i = 0 ; i <= nums.size() ; i++)
        {
            ans = ans ^ i;
        }

        return ans;
    }
};