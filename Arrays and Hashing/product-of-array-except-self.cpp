#include<iostream>
#include<vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> ans(n,1);
        int prefix = 1, postfix =1;
        for(int i = 0; i < n; i++)
        {
            ans[i] = ans[i]*prefix;
            prefix = prefix*nums[i];
        }

        for(int i = n-1; i > -1; i--)
        {
            ans[i] = ans[i]*postfix;
            postfix = postfix*nums[i];
        }

        return ans;
    }
};