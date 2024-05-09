#include<iostream>
#include<vector>
#include<string>

class Solution {
public:

    std::string encode(std::vector<std::string>& strs) {
        std::string encoded = "";
        for(std::string str : strs)
        {
            int length = str.length();
            std::string prefix = std::to_string(length) + std::string("#");
            encoded = encoded + prefix + str;
        }
        return encoded;
    }

    std::vector<std::string> decode(std::string s) {
        std::vector<std::string> decoded ;
        
        for (int i = 0; i < s.length() ; i++)
        {
            std::string len = "";
            while(s[i] != '#')
            {
                len = len + s[i];
                i++;
            }
            i++;
            int length = std::stoi(len);

            len = s.substr(i,length);
            decoded.push_back(len);
            i = i + length -1;      
        }
        return decoded;
    }
};