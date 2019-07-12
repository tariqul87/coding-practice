#include <bits/stdc++.h>
#include "../data_structures/tree.cpp"
using namespace std;

void intArrayInput(int count, vector<int> &array);
void intArrayInputWithCount(vector<int> &array);
void printIntArray(vector<int> array, string delemeter);
void printDoubleIntArray(vector<vector<int>> array, string delemeter);

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
    vector<vector<int>> maxArray;
    map<int, int> numToIndex;
    TreeNode *createNode(int start, int end)
    {
        if (start > end || start == maxArray.size() || end == maxArray.size())
        {
            return NULL;
        }
        int val = maxArray[start][end];
        int index = numToIndex[val];
        TreeNode *node = new TreeNode(val);
        node->left = createNode(start, index - 1);
        node->right = createNode(index + 1, end);

        return node;
    }
    void constructArray(vector<int> array)
    {
        for (int i = 0; i < array.size(); i++)
        {
            vector<int> tempArray(array.size(), 0);
            int max = array[i];
            numToIndex[array[i]] = i;
            for (int j = i; j < array.size(); j++)
            {
                if (max < array[j])
                {
                    max = array[j];
                }
                tempArray[j] = max;
            }
            maxArray.push_back(tempArray);
        }
    }
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        constructArray(nums);
        TreeNode *root = createNode(0, nums.size() - 1);
        return root;
    }
    void printTree(TreeNode *root)
    {
        if (!root)
        {
            return;
        }

        printTree(root->left);
        cout << root->val << " ";
        printTree(root->right);
    }
};

int main(void)
{
    vector<int> array({2, 4, 3, 7});
    Solution solution;
    solution.printTree(solution.constructMaximumBinaryTree(array));
    return 0;
}

void printIntArray(vector<int> array, string delemeter)
{
    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] << delemeter;
    }

    cout << endl;
}

void printDoubleIntArray(vector<vector<int>> array, string delemeter)
{
    for (int i = 0; i < array.size(); i++)
    {
        for (int j = 0; j < array[i].size(); j++)
        {
            cout << array[i][j] << delemeter;
        }
        cout << endl;
    }

    cout << endl;
}

void intArrayInput(int count, vector<int> &array)
{
    for (int i = 0; i < count; i++)
    {
        int x;
        cin >> x;
        array.push_back(x);
    }
}

void intArrayInputWithCount(vector<int> &array)
{
    int count;
    cin >> count;
    intArrayInput(count, array);
}