#include<iostream>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {} 
};

class Solution {
public:

    int maxDepthRecurser(TreeNode* node, int curr_depth)
    {
        if(!node->left && !node->right) return curr_depth;

        int left = 0, right = 0;
        if (node->left) left = maxDepthRecurser(node->left, curr_depth+1);
        if (node->right) right = maxDepthRecurser(node->right, curr_depth+1);

        return std::max(left, right);
    }

    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int max_depth = 1;
        max_depth = maxDepthRecurser(root, 1);
        return max_depth;
    }
};
