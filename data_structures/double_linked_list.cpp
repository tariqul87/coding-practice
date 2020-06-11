#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val, key;
    ListNode *next;
    ListNode *prev;
    ListNode(int k, int value)
    {
        key = key;
        val = value;
        prev = next = NULL;
    };
};

class LRUCache
{
    ListNode *head;
    ListNode *tail;
    unordered_map<int, ListNode *> keyMap;
    int size;
    int capacity;

public:
    LRUCache(int cap)
    {
        head = tail = NULL;
        size = 0;
        capacity = cap;
    }
    void add(ListNode *node)
    {
        if (!head)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            tail->next->prev = tail;
            tail = tail->next;
        }

        size++;
    }
    void put(int key, int value)
    {
        if (keyMap.find(key) != keyMap.end())
        {
            deleteNode(keyMap[key]);
        }

        if (size == capacity)
        {
            deleteNode(head);
        }

        ListNode *node = new ListNode(key, value);
        add(node);
        keyMap[key] = node;
    }
    int get(int key)
    {
        if (keyMap.find(key) == keyMap.end())
        {
            return -1;
        }

        int val = keyMap[key]->val;
        deleteNode(keyMap[key]);
        add(key, val);

        return val;
    }
    void deleteNode(ListNode *ptr)
    {
        if (!ptr)
        {
            return;
        }

        size--;
        if (ptr == head && ptr == tail)
        {
            head = tail = NULL;
            free(ptr);
        }

        if (ptr == head)
        {
            head = head->next;

            if (head)
            {
                head->prev = NULL;
            }
            free(ptr);

            return;
        }

        if (ptr == tail)
        {
            tail = tail->prev;

            if (tail)
            {
                tail->next = NULL;
            }
            free(ptr);

            return;
        }

        ListNode *prev = ptr->prev;
        ListNode *next = ptr->next;

        if (prev)
        {
            prev->next = next;
        }

        if (next)
        {
            next->prev = prev;
        }
    }
    void print()
    {
        ListNode *ptr = head;

        while (ptr)
        {
            cout << ptr->val << "-";
            ptr = ptr->next;
        }

        cout << endl;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(void)
{
    cout << "Double linked list" << endl;
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cache.put(3, 3);
    cache.print();
    cache.put(4, 4);
    cache.print();
    return 0;
}