#include<iostream>
#include<vector>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int area = 0;
        while(left < right)
        {
            int width = right - left;
            area = std::max(area, width*std::min(height[left], height[right]));
            if(height[left] >  height[right]) right--;
            else left++;
        }
        return area;
    }
};