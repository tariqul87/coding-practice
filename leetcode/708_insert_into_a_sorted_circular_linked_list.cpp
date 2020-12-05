#include "array.cpp"

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    bool isValidPosition(Node* ptr, int val) {
        if (ptr->val > ptr->next->val) {
            return val <= ptr->next->val || val >= ptr->val;
        }
        
        if (ptr->val <= val && val <= ptr->next->val) {
            return true;
        }
        
        return false;
    }
    Node* insert(Node* head, int insertVal) {
        Node* node = new Node(insertVal);
        
        if (!head) {
            node->next = node;
            return node;
        }
        
        Node *ptr = head;
        
        while(ptr->next != head && !isValidPosition(ptr, insertVal)) {
            ptr = ptr->next;
        }
        
        node->next = ptr->next;
        ptr->next = node;
        
        return head;
    }
};