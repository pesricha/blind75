#include<iostream>
#include<vector>

class Solution {
public:

    int binarySearch(std::vector<int>& nums, int target, int low, int high)
    {
        if(low > high) return -1;
        int mid = low + (high-low)/2;
        if(nums[mid] == target) return mid;
        else if(nums[mid]>target) return binarySearch(nums, target, low, mid-1);
        else return binarySearch(nums,target, mid+1, high );
    }

    int findMiddle(std::vector<int>& nums)
    {
        int low = 0;
        int high = nums.size() - 1;
        int mid;

        while(low <= high)
        {
            mid = low + (high - low)/2;
            
            if(nums[mid] < nums[mid-1]) return mid;
            else if (nums[mid] > nums[high]) low = mid+1;
            else high = mid;
            
        }

        return mid;
    }

    int search(std::vector<int>& nums, int target) {
        
        int low = 0; 
        int high = nums.size() - 1;

        if(high == 0)
        {
            if (nums[0] == target) return 0;
            return -1;
        }

        if(high == 1)
        {
            if (nums[0] == target) return 0;
            if (nums[1] == target) return 1;
            return -1; 
        }

        if (nums[low] < nums[high]) return binarySearch(nums, target, low, high);

        int start = findMiddle(nums);
        
        std::cout << "Middle   " << start << std::endl;
        
        int left = binarySearch(nums, target, low, start-1);
        int right = binarySearch(nums, target, start, high);
        if (left == -1) return right;
        return left;
    }
};