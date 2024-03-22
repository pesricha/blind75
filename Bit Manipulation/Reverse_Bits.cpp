#include<iostream>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        u_int32_t ans = 0;

        for (int i = 0 ; i < 32 ; i++)
        {
            ans = ans + n%2;
            if (i == 31) break;
            ans = ans << 1;
            n = n >> 1;
        }

        return ans;
    }
};