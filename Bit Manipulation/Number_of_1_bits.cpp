#include<iostream>

class Solution {
public:
    int hammingWeight(int n) {
        
        int number_of_1_bits = 0;

        while(n)
        {
            n = n&(n-1);
            number_of_1_bits++;
        }

        return number_of_1_bits;
    }
};