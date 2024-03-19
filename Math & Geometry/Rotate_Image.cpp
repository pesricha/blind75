#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // Take Transpose
        for (int i = 0 ; i < n ; i++)
        {
            for (int j = i+1; j < n  ; j++)
            {
                matrix[i][j] = matrix[i][j] + matrix[j][i];
                matrix[j][i] = matrix[i][j] - matrix[j][i];
                matrix[i][j] = matrix[i][j] - matrix[j][i];
            }
        }
        // Reverse the rows
        for (int i = 0 ; i < n ; i++)
        {
            int left = 0; 
            int right = n-1;
            while (left < right)
            {
                std::swap(matrix[i][left], matrix[i][right]);
                left ++;
                right --;
            }
        }
    }
};
