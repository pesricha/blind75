#include<iostream>
#include<string>
#include<vector>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        std::vector<int> chars(26,0);
        int n = s.size();
        if (n != t.size()) return false;
        for(int i = 0; i < n ; i++)
        {
            chars[int(s[i] - 'a')] ++;
            chars[int(t[i] - 'a')] --;
        }

        for (int num : chars)
        {
            if (num) return false;
        }

        return true;
    }
};