#include<iostream>
#include<unordered_map>

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pval = p->val;
        int qval = q->val;
        TreeNode* ptr = root;  

        while(true)
        {
            if (pval < ptr->val && qval < ptr->val) ptr = ptr->left;

            else if (pval > ptr->val && qval > ptr->val) ptr = ptr->right;

            else return ptr;
        }

    }
};