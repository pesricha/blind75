#include<iostream>

class Solution {
public:
    int climbStairs(int n) {
        
        if (n==1 || n==2) return n;
    
        int num1 = 1, num2 =2;

        for(int i = 3; i <= n ; i++)
        {
            int temp  = num2 + num1;
            num1 = num2;
            num2 = temp;
        }

        return num2;
    }
};