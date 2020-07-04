/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(INT_MIN);
        ListNode* ptr = head;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for(int i=0; i<lists.size(); i++) {
            if (lists[i]) {
                pq.push(make_pair(lists[i]->val, i));
                lists[i] = lists[i]->next;
            }
        }
        
        while(!pq.empty()) {
            int val = pq.top().first, i = pq.top().second;
            pq.pop();
            
            ptr->next = new ListNode(val);
            ptr = ptr->next;
            
            if(lists[i]) {
                pq.push(make_pair(lists[i]->val, i));
                lists[i] = lists[i]->next;
            }
        }
        
        return head->next;
    }
};