#include<iostream>
#include<vector>

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

    bool recurser(TreeNode* root, int64_t min, int64_t max)
    {
        if(!root) return true;
        if(root->val <= min || root->val >= max) return false;
        return recurser(root->left, min, root->val) && recurser(root->right, root->val,max);
    }
        

    bool isValidBST(TreeNode* root) 
    {
        int64_t min = INT64_MIN;
        int64_t max = INT64_MAX;
        return recurser(root, min, max);
    }
};