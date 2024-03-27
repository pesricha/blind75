#include<iostream>
#include<vector>

class Solution {
public:
    int findMin(std::vector<int>& nums) {
        
        int low = 0;
        int high = nums.size()-1;

        if (high == 0) return nums[0];
        if (high == 1) 
        {
            if (nums[0] < nums[1]) return nums[0];
            return nums[1];
        }

        if (nums[low] < nums[high]) return nums[low];

        while(low <= high)
        {
            int mid = low + (high -low)/2;
            if(nums[mid] < nums[mid - 1]) return nums[mid];
            else if (nums[mid] > nums[high]) low = mid+1;
            else high = mid;
        }
        return 5001;
    }
};