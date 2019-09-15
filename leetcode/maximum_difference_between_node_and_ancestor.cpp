#include <bits/stdc++.h>
#include "../data_structures/tree.cpp"
using namespace std;

class Solution {
public:
    int maxDistance = 0;
    vector<int> findMaxDistance(TreeNode *root) {
        if (!root) {
            return {};
        }

        vector<int> left, right, arr;
        left = findMaxDistance(root->left);
        right = findMaxDistance(root->right);

        arr.insert(arr.end(), left.begin(), left.end());
        arr.insert(arr.end(), right.begin(), right.end());

        for(int i=0; i<arr.size(); i++) {
            int distance = abs(root->val - arr[i]);

            if (maxDistance < distance) {
                maxDistance = distance;
            }
        }
        arr.insert(arr.begin(), root->val);
        return arr;

    }
    int maxAncestorDiff(TreeNode* root) {
        findMaxDistance(root);
        return maxDistance;
    }
};

int main(void) {
    vector<int> arr({8,3,10,1,6,14,4,7,13});
    TreeNode *root = createBinarySearchTreeFromIntArray(arr);
    printInOrder(root);
    return 0;
}