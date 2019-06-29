#include <bits/stdc++.h>
using namespace std;

class binarySearchTreeNode
{
public:
    int val;
    binarySearchTreeNode *left;
    binarySearchTreeNode *right;
    binarySearchTreeNode(int value)
    {
        val = value;
        left = NULL;
        right = NULL;
    }
};

void addNode(int value, binarySearchTreeNode *root)
{
    if (value <= root->val)
    {
        if (root->left)
        {
            addNode(value, root->left);
            return;
        }

        root->left = new binarySearchTreeNode(value);
        return;
    }

    if (root->right)
    {
        addNode(value, root->right);
        return;
    }

    root->right = new binarySearchTreeNode(value);
}

void printInOrder(binarySearchTreeNode *root)
{
    if (!root)
    {
        return;
    }
    if (root->left)
    {
        printInOrder(root->left);
    }

    cout << root->val << " ";

    printInOrder(root->right);
}

binarySearchTreeNode *createBinarySearchTreeFromIntArray(vector<int> array)
{
    binarySearchTreeNode *root = new binarySearchTreeNode(array[0]);

    for (int i = 1; i < array.size(); i++)
    {
        addNode(array[i], root);
    }

    return root;
}