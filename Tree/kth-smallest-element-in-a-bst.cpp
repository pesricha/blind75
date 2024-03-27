#include<iostream>
#include<stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    int kthSmallest(TreeNode* root, int k) {
        std::stack<TreeNode*> mystack;
        TreeNode* node = root;
        int counter = 0;

        while(1)
        {
            if(node)
            {
                mystack.push(node);
                node = node->left; 
            }
            else
            {
                if(mystack.empty()) break;
                node = mystack.top();
                mystack.pop();
                
                counter++;
                if(counter == k) return node->val;

                node = node->right;
            }
        }
        return -1;
    }   
};