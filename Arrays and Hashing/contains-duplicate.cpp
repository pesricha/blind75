#include<iostream>
#include<vector>
#include<unordered_map>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_map<int,int> map;

        for(int num: nums)
        {
            if (map[num]) return true;
            map[num] = 1;
        }
        return false;
    }
};