#include<iostream>
#include<vector>
#include<unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int,int> map;
        std::vector<int> ans;
        for (int i =0 ; i < nums.size() ; i++)
        {
            if(map[target- nums[i]])
            {
                ans.push_back(map[target- nums[i]] - 1);
                ans.push_back(i);
            }

            map[nums[i]] = i+1;
        }
        return ans;
    }
};