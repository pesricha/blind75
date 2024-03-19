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

    void Swap(TreeNode* &left, TreeNode* &right)
    {
        TreeNode* temp = left;
        left = right;
        right = temp;

        if(left) Swap(left->left, left->right);
        if(right) Swap(right->left, right->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        Swap(root->left,root->right);
        return root;
    }
};
