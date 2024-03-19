#include<iostream>
#include<vector>
#include<algorithm>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        const int length = nums.size();
        
        int prev1 = 0;
        int prev2 = 0;

        for (int num : nums)
        {
            int tmp = prev1;
            prev1 = std::max(prev1, prev2+num);
            prev2 = tmp;
        }

        return prev1;
    }
};