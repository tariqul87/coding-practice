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
class BSTIterator {
    stack<TreeNode*> st;
    void updateValues(TreeNode* root) {
        if(!root) {
            return;
        }
        
        st.push(root);
        updateValues(root->left);
    }
public:
    BSTIterator(TreeNode* root) {
        updateValues(root);
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* node = st.top();
        int val = node->val;
        
        st.pop();
        updateValues(node->right);
        
        return val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */