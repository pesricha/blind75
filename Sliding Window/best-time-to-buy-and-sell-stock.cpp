#include<iostream>
#include<vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        
        int buypoint = prices[0];
        int maxProf = 0;

        for(int i = 1; i < prices.size() ; i++)
        {
            if(prices[i] < buypoint) buypoint = prices[i];
            else maxProf = std::max(maxProf, prices[i] - buypoint); 
        }

        return maxProf;
    }
};