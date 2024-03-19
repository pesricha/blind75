#include<iostream>
#include<vector>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int length = nums.size();

        int current_goal = length - 1;

        for (int i = length -2; i >= 0 ; i--)
        {
            if( nums[i] + i >= current_goal)
            {
                current_goal = i;
            }
        }

        std::cout << "Current Goal : " << current_goal << std::endl;

        if(!current_goal) return true;
        return false;
    }
};