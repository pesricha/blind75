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

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;

        int p_val = p->val;
        int q_val = q->val;

        return (p_val == q_val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        bool ans = false;
        
        if (!root) return false;

        if (root->val == subRoot->val) ans = isSameTree(root,subRoot);

        if (ans) return ans;

        bool left_check = isSubtree(root->left, subRoot);
        bool right_check = isSubtree(root->right, subRoot);

        if(left_check || right_check) return true;

        return false;
    }
};