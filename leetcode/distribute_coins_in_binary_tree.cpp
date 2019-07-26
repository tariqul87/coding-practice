#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    int moves = 0;
    int distributeCoins(TreeNode *root)
    {
        getNumberOfMoves(root);
        return moves;
    }
    int getNumberOfMoves(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        int leftSubTreeCoins = getNumberOfMoves(root->left);
        int rightSubTreeCoins = getNumberOfMoves(root->right);
        moves += abs(root->val - 1 + leftSubTreeCoins + rightSubTreeCoins);

        return root->val - 1 + leftSubTreeCoins + rightSubTreeCoins;
    }
};