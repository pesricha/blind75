#include<iostream>
#include<unordered_map>

class Solution {
public:
    int characterReplacement(std::string s, int k) {

        int left = 0;
        int right = 0;
        int ans = 0;
        int most_popular_charecter;
        std::unordered_map<char,int> char_to_count;

        for(right = 0; right < s.size(); right++)
        {
            char_to_count[s[right]]++;
            most_popular_charecter = std::max(most_popular_charecter, char_to_count[s[right]]);

            if((right-left+1) - most_popular_charecter > k)
            {
                char_to_count[left]--;
                left++;
            }

            else
            {
                ans = std::max(ans, (right - left + 1));
            }
        }
    }
};