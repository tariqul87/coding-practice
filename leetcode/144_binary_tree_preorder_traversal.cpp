#include "array.cpp"

/**
 * Definition for a binary tree node.
**/
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        
        if (!root) {
            return result;
        }
        
        vector<TreeNode*> nodes;
        nodes.push_back(root);
        
        while(nodes.size()) {
            TreeNode* node = nodes.back();
            result.push_back(node->val);
            nodes.pop_back();
            
            if (node->right) {
                nodes.push_back(node->right);
            }
            
            if (node->left) {
                nodes.push_back(node->left);
            }
        }
        
        return result;
    }
};