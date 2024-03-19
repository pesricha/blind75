#include<iostream>
#include<string.h>
#include<stack>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> my_stack;
        int len = s.size();
        for (int i = 0 ; i < len; i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                my_stack.push(s[i]);
            }

            else
            {
                if (my_stack.empty()) return false;
                char top = my_stack.top();

                if ((s[i] == ')' && top != '(' )
                ||  (s[i] == ']' && top != '[' )
                ||  (s[i] == '}' && top != '{' )
                ) 
                {
                    return false;
                }

                my_stack.pop();

            }
        }

        return my_stack.empty();
    }
};
