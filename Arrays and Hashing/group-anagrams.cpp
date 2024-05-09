#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> map;
        std::vector<std::vector<std::string>> ans;

        for(std::string &str : strs)
        {
            std::string key = str;
            std::sort(key.begin(), key.end());
            map[key].push_back(str);
        }

        for(auto i = map.begin(); i != map.end() ; i++)
        {
            ans.push_back(i->second);
        }

        return ans;
    }
};