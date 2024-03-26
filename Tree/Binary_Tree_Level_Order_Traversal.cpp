#include<iostream>
#include<vector>
#include<queue>

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

    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::queue<TreeNode*> nodeQ;
        std::queue<int> levleQ;
        nodeQ.push(root);
        levleQ.push(1);
        std::vector<std::vector<int>> ans;
        if(!root) return ans;
        while(!nodeQ.empty())
        {
            TreeNode* current_node = nodeQ.front();
            int current_level = levleQ.front();
            if(ans.size() < current_level) 
            {   
                ans.push_back(std::vector<int>());
            }

            ans[current_level-1].push_back(current_node->val);

            if(current_node-> left)
            {
                nodeQ.push(current_node-> left);
                levleQ.push(current_level + 1);
            } 
            if(current_node->right)
            {
                nodeQ.push(current_node->right);
                levleQ.push(current_level + 1);
            }

            nodeQ.pop();
            levleQ.pop();
        }
        return ans;
    }
};