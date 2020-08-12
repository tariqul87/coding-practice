/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void updateParentMap(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentMap) {
        vector<TreeNode*> nodes = {root};
        int index = 0;
        
        while(index < nodes.size()) {
            TreeNode* node = nodes[index];
            
            if (node->left) {
                nodes.push_back(node->left);
                parentMap[node->left] = node;
            }
            
            if (node->right) {
                nodes.push_back(node->right);
                parentMap[node->right] = node;
            }
            
            index++;
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if(!root) {
            return {};
        }
        
        unordered_map<TreeNode*, TreeNode*> parentMap;
        updateParentMap(root, parentMap);
        
        deque<TreeNode*> dq = {target};
        unordered_set<TreeNode*> seenNodes;
        seenNodes.insert(target);
        
        for(int i=0; i<K; i++) {
            int size = dq.size();
            while(size) {
                TreeNode* leftChild = dq.front()->left;
                TreeNode* rightChild = dq.front()->right;
                TreeNode* parent = parentMap[dq.front()];
                
                if (leftChild && seenNodes.find(leftChild) == seenNodes.end()) {
                    dq.push_back(leftChild);
                    seenNodes.insert(leftChild);
                }
                
                if (rightChild && seenNodes.find(rightChild) == seenNodes.end()) {
                    dq.push_back(rightChild);
                    seenNodes.insert(rightChild);
                }
                
                if (parent && seenNodes.find(parent) == seenNodes.end()) {
                    dq.push_back(parent);
                    seenNodes.insert(parent);
                }
                
                dq.pop_front();
                size--;
            }
        }
        
        vector<int> result;
        
        for(TreeNode* node: dq) {
            result.push_back(node->val);
        }
        
        return result;
    }
};
