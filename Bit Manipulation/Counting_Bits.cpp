#include<iostream>
#include<vector>
class Solution {
public:

    int hammingWeight(int n)
    {
        int count = 0;

        while(n)
        {
            n=n&(n-1);
            count++;
        }

        return count;
    }

    std::vector<int> countBits(int n) {
        
        std::vector<int> ans;
        for(int i = 0 ; i<=n ; i++){
            ans.push_back(hammingWeight(i));
        }

        return ans;
    }
};