#include<iostream>
#include<unordered_map>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, int> char_to_index;
        int size = s.size();
        int left = 0;
        int max_length = 0;

        for (int right = 0; right < size ; right++)
        {
            if(char_to_index.count(s[right]) == 0 || char_to_index[s[right]] < left)
            {
                char_to_index[s[right]] = right;
                max_length = std::max(max_length, right - left + 1);
            }

            else
            {
                left = char_to_index[s[right]] + 1;
                char_to_index[s[right]] = right;
            }
        }

        return max_length;
    }
};