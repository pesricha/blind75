#include<iostream>
#include<vector>
#include<unordered_map>

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

    TreeNode* build(std::vector<int>& preorder, std::vector<int>& inorder, int &index, int i, int j)
    {
        if(i>j) return nullptr;

        TreeNode* root = new TreeNode(preorder[index]);

        int split = 0;
        for (int i = 0; i < inorder.size(); i++) {
            if (preorder[index] == inorder[i]) {
                split = i;
                break;
            }
        }
        index++;
        root->left = build(preorder,inorder, index, i, split-1);
        root->right = build(preorder, inorder, index, split+1, j);
        return root;
    }

    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder)
    {
        int index = 0;
        return build(preorder, inorder, index, 0, inorder.size()-1);
    }

};


// class Solution {
// public:
//     TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        
//         std::unordered_map<int,int> value_to_idx;
//         int n_elements = inorder.size();
//         TreeNode* root = new TreeNode(preorder[0]);
        
//         for (int i = 0; i < n_elements; i++)
//         {
//             if (inorder[i] == preorder[0])
//             {
//                 value_to_idx[inorder[i]] = i;
//             }
//         }

//         for (int i = 1; i < n_elements; i++)
//         {
//             int curr_elem = preorder[i];
//             int curr_idx;
            
//             for (int k = 0; k < n_elements; k++)
//             {
//                 if (inorder[k] == curr_elem)
//                 {
//                     curr_idx = k;
//                 }
//             }

//             TreeNode * node = root;
//             TreeNode * prev;
//             while(node)
//             {
//                 if (value_to_idx[node->val] < curr_idx)
//                 {
//                     prev = node;
//                     node = node -> right;
//                     if(!node)
//                     {
//                         prev->right = new TreeNode(curr_elem);
//                         break;
//                     }
//                 }
//                 else
//                 {
//                     prev = node;
//                     node = node->left;
//                     if(!node)
//                     {
//                         prev->left = new TreeNode(curr_elem);
//                         break;
//                     }
//                 }
//             }

//             value_to_idx[curr_elem] = curr_idx;

//         }
//         return root;
//     }
// };