#include "array.cpp"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool seen = false;
    int previousVal = NULL;
    bool isValidBST(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }

        if (!isValidBST(root->left) || (seen && previousVal >= root->val))
        {
            return false;
        }

        seen = true;
        previousVal = root->val;

        return isValidBST(root->right);
    }
};