#include <bits/stdc++.h>
#include "../data_structures/tree.cpp"
using namespace std;

typedef binarySearchTreeNode TreeNode;

class Solution
{
public:
    vector<int> cumulativeSum;
    void generateCumulativeSum(TreeNode *root)
    {
        if (!root)
        {
            return;
        }

        generateCumulativeSum(root->left);
        int size = cumulativeSum.size();
        if (size)
        {
            cumulativeSum.push_back(cumulativeSum[size - 1] + root->val);
        }
        else
        {
            cumulativeSum.push_back(root->val);
        }
        generateCumulativeSum(root->right);
    }
    void changeTree(TreeNode *root)
    {
        if (!root)
        {
            return;
        }

        changeTree(root->left);
        root->val = cumulativeSum[cumulativeSum.size() - 1] - cumulativeSum[0] + root->val;
        cumulativeSum.erase(cumulativeSum.begin());
        changeTree(root->right);
    }
    TreeNode *bstToGst(TreeNode *root)
    {
        generateCumulativeSum(root);
        changeTree(root);
        return root;
    }
};

int main(void)
{
    vector<int> array({4, 1, 6, 0, 2, 5, 7, 3, 8});
    TreeNode *root = createBinarySearchTreeFromIntArray(array);
    Solution solution;
    printInOrder(solution.bstToGst(root));
    return 0;
}
