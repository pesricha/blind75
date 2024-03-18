#include<bits/stdc++.h>
using namespace std;

// Solution Starts here
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int columns = matrix[0].size();
        int rows = matrix.size();
        int l_rows = 0;
        int l_columns = -1;

        std::vector<int> answer;
        int elements = rows*columns , i=0, j=0 ;
        std::string direction = "r";

        while (elements)
        {
            if(direction == "r")
            {
                
                if( j == columns)
                {
                    direction = "d";
                    j--;
                    i++;
                    columns --;
                    continue;
                }

                answer.push_back(matrix[i][j]);
                elements--;
                j++;
                
            }

            else if (direction =="d")
            {
                if (i == rows)
                {
                    direction = "l";
                    i--;
                    j--;
                    rows--;
                    continue;
                }

                answer.push_back(matrix[i][j]);
                elements--;
                i++;
            }

            else if(direction == "l")
            {
                
                if( j == l_columns)
                {
                    direction = "u";
                    j++;
                    i--;
                    l_columns ++;
                    continue;
                }

                answer.push_back(matrix[i][j]);
                elements--;
                j--;
                
            }

            else
            {
                if (i == l_rows)
                {
                    direction = "r";
                    l_rows ++;
                    i++;
                    j++;
                    continue;
                }

                answer.push_back(matrix[i][j]);
                elements--;
                i--;
            }
        }
        return answer;
    }
};

// Solution End here
int main()
{
    std::cout << "Hello World!\n" ;
    return 0; 
}