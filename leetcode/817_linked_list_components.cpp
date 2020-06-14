/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int count = 0;
    ListNode* getNextPresentPair(ListNode* ptr, unordered_set<int>& nodes) {
        while(ptr) {
            if (ptr->next && nodes.find(ptr->val) != nodes.end() && nodes.find(ptr->next->val) != nodes.end()) {
                return ptr;
            }
            
            if (nodes.find(ptr->val) != nodes.end()) {
                count++;
                nodes.erase(nodes.find(ptr->val));
            }
            
            ptr = ptr->next;
        }
        
        return ptr;
    }
    int numComponents(ListNode* head, vector<int>& G) {
        if (G.size() <= 1) {
            return G.size();
        }
        
        unordered_set<int> nodes(G.begin(), G.end());
        ListNode* ptr = head;
        
        while(ptr && nodes.size()) {
            ptr = getNextPresentPair(ptr, nodes);
            
            if (ptr) {
                count++;
                while(ptr && nodes.find(ptr->val) != nodes.end()) {
                    nodes.erase(nodes.find(ptr->val));
                    ptr = ptr->next;
                }
            }
        }
        
        return count;
    }
};